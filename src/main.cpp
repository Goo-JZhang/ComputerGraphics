// Hand Example
// Author: Yi Kangrui <yikangrui@pku.edu.cn>

//#define DIFFUSE_TEXTURE_MAPPING

#include "gl_env.h"

#include <cstdlib>
#include <cstdio>
#include <random>
#include "config.h"

#include "hand_motion.h"

#ifndef M_PI
#define M_PI (3.1415926535897932)
#endif

#include <iostream>
#include <imgui/imgui.h>
#include <imgui/imgui_impl_glfw.h>
#include <imgui/imgui_impl_opengl3.h>
//#include "skeletal_mesh.h"

//#include <glm/gtc/matrix_transform.hpp>

namespace SkeletalAnimation {
    const char *vertex_shader_330 =
            "#version 330 core\n"
            "const int MAX_BONES = 100;\n"
            "uniform mat4 u_bone_transf[MAX_BONES];\n"
            "uniform mat4 u_mvp;\n"
            "layout(location = 0) in vec3 in_position;\n"
            "layout(location = 1) in vec2 in_texcoord;\n"
            "layout(location = 2) in vec3 in_normal;\n"
            "layout(location = 3) in ivec4 in_bone_index;\n"
            "layout(location = 4) in vec4 in_bone_weight;\n"
            "out vec2 pass_texcoord;\n"
            "void main() {\n"
            "    float adjust_factor = 0.0;\n"
            "    for (int i = 0; i < 4; i++) adjust_factor += in_bone_weight[i] * 0.25;\n"
            "    mat4 bone_transform = mat4(1.0);\n"
            "    if (adjust_factor > 1e-3) {\n"
            "        bone_transform -= bone_transform;\n"
            "        for (int i = 0; i < 4; i++)\n"
            "            bone_transform += u_bone_transf[in_bone_index[i]] * in_bone_weight[i] / adjust_factor;\n"
            "	 }\n"
            "    gl_Position = u_mvp * bone_transform * vec4(in_position, 1.0);\n"
            "    pass_texcoord = in_texcoord;\n"
            "}\n";

    const char *fragment_shader_330 =
            "#version 330 core\n"
            "uniform sampler2D u_diffuse;\n"
            "in vec2 pass_texcoord;\n"
            "out vec4 out_color;\n"
            "void main() {\n"
            #ifdef DIFFUSE_TEXTURE_MAPPING
            "    out_color = vec4(texture(u_diffuse, pass_texcoord).xyz, 1.0);\n"
            #else
            "    out_color = vec4(pass_texcoord, 0.0, 1.0);\n"
            #endif
            "}\n";
}

static void error_callback(int error, const char *description) {
    fprintf(stderr, "Error: %s\n", description);
}

static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}

int spr_state = READY;
bool motion_start = false;
bool random_game = false;
bool gun_ready = false;
bool gun_start = false;
bool winwin = false;

glm::fvec3 camera_eye = glm::fvec3(0.0, 0.0, -1.0);
glm::fvec3 camera_center = glm::fvec3(0.0, 0.0, 0.0);
glm::fvec3 camera_up = glm::fvec3(0.0, 1.0, 0.0);

float angle_step = 0.02*M_PI;

float move_step = 0.1;

void (*current_hand_motion)(SkeletalMesh::SkeletonModifier& ,glm::fmat4& ,float ,float);

int keys = 0;

void draw_ui()
{
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
    ImGui::Begin("Hand controller");
    ImGui::Text("Scissor Paper Rock Game");
    motion_start |= ImGui::RadioButton("ready", &spr_state, READY);
    ImGui::SameLine();
    motion_start |= ImGui::RadioButton("scissor", &spr_state, SCISSOR);
    ImGui::SameLine();
    motion_start |= ImGui::RadioButton("paper", &spr_state, PAPER);
    ImGui::SameLine();
    motion_start |= ImGui::RadioButton("rock", &spr_state, ROCK);
    random_game = ImGui::Button("random");
    motion_start |= random_game;
    ImGui::Text("Hand Gun");
    gun_ready |= ImGui::Button("aiming");
    motion_start |= gun_ready;
    ImGui::SameLine();
    gun_start |= ImGui::Button("shoot!");
    motion_start |= gun_start;
    ImGui::Text("Good Good");
    winwin |= ImGui::Button("Win!");
    motion_start |= winwin;
    ImGui::End();
}

void getKeyInput(GLFWwindow *window,int &key)
{
    key = 0;
    if(glfwGetKey(window,(int)GLFW_KEY_A)) key = GLFW_KEY_A;
    if(glfwGetKey(window,(int)GLFW_KEY_W)) key = GLFW_KEY_W;
    if(glfwGetKey(window,(int)GLFW_KEY_S)) key = GLFW_KEY_S;
    if(glfwGetKey(window,(int)GLFW_KEY_D)) key = GLFW_KEY_D;
    if(glfwGetKey(window,(int)GLFW_KEY_UP)) key = GLFW_KEY_UP;
    if(glfwGetKey(window,(int)GLFW_KEY_DOWN)) key = GLFW_KEY_DOWN;
    if(glfwGetKey(window,(int)GLFW_KEY_LEFT)) key = GLFW_KEY_LEFT;
    if(glfwGetKey(window,(int)GLFW_KEY_RIGHT)) key = GLFW_KEY_RIGHT;
}

void change_camera(glm::fvec3&eye, glm::fvec3&center, glm::fvec3&up)
{
    if(keys==GLFW_KEY_W)
    {
        eye = eye + move_step*up;
        center = center + move_step*up;
    }
    if(keys==GLFW_KEY_UP)
    {
        glm::fvec3 rotate_axis = glm::cross(up,center - eye);
        glm::fmat3 rotate_mat = glm::fmat3(glm::rotate(glm::identity<glm::fmat4>(),
                                            -angle_step,
                                            rotate_axis));
        up = rotate_mat*up;
        glm::normalize(up);
        center = eye + rotate_mat*(center - eye);
    }
    if(keys==GLFW_KEY_S)
    {
        eye = eye - move_step*up;
        center = center - move_step*up;
    }
    if(keys==GLFW_KEY_DOWN)
    {
        glm::fvec3 rotate_axis = glm::cross(up,center - eye);
        glm::fmat3 rotate_mat = glm::fmat3(glm::rotate(glm::identity<glm::fmat4>(),
                                            angle_step,
                                            rotate_axis));
        up = rotate_mat*up;
        glm::normalize(up);
        center = eye + rotate_mat*(center - eye);
    }
    if(keys==GLFW_KEY_A)
    {
        glm::fvec3 left = glm::cross(up, center - eye);
        glm::normalize(left);
        eye = eye + move_step*left;
        center = center + move_step*left;
    }
    if(keys==GLFW_KEY_LEFT)
    {
        glm::fvec3 rotate_axis = up;
        glm::fmat3 rotate_mat = glm::fmat3(glm::rotate(glm::identity<glm::fmat4>(),
                                            angle_step,
                                            rotate_axis));
        center = eye + rotate_mat*(center - eye);
    }
    if(keys==GLFW_KEY_D)
    {
        glm::fvec3 left = glm::cross(up, center - eye);
        glm::normalize(left);
        eye = eye - move_step*left;
        center = center - move_step*left;
    }
    if(keys==GLFW_KEY_RIGHT)
    {
        glm::fvec3 rotate_axis = up;
        glm::fmat3 rotate_mat = glm::fmat3(glm::rotate(glm::identity<glm::fmat4>(),
                                            -angle_step,
                                            rotate_axis));
        center = eye + rotate_mat*(center - eye);
    }
}

int main(int argc, char *argv[]) {
    GLFWwindow *window;
    GLuint vertex_shader, fragment_shader, program;

    glfwSetErrorCallback(error_callback);

    if (!glfwInit())
        exit(EXIT_FAILURE);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__ // for macos
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    window = glfwCreateWindow(800, 800, "OpenGL output", NULL, NULL);
    if (!window) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwSetKeyCallback(window, key_callback);

    glfwMakeContextCurrent(window);
    glfwSwapInterval(0);

    if (glewInit() != GLEW_OK)
        exit(EXIT_FAILURE);

    vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_shader, 1, &SkeletalAnimation::vertex_shader_330, NULL);
    glCompileShader(vertex_shader);

    fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_shader, 1, &SkeletalAnimation::fragment_shader_330, NULL);
    glCompileShader(fragment_shader);

    program = glCreateProgram();
    glAttachShader(program, vertex_shader);
    glAttachShader(program, fragment_shader);
    glLinkProgram(program);
    //glfwSetScrollCallback(window,scroll_call_back);

    int linkStatus;
    if (glGetProgramiv(program, GL_LINK_STATUS, &linkStatus), linkStatus == GL_FALSE)
        std::cout << "Error occured in glLinkProgram()" << std::endl;

    SkeletalMesh::Scene &sr = SkeletalMesh::Scene::loadScene("Hand", DATA_DIR"/Hand.fbx");
    if (&sr == &SkeletalMesh::Scene::error)
        std::cout << "Error occured in loadMesh()" << std::endl;

    sr.setShaderInput(program, "in_position", "in_texcoord", "in_normal", "in_bone_index", "in_bone_weight");

    srand(time(0));
    float passed_time;
    float motion_start_time = (float) glfwGetTime();
    SkeletalMesh::SkeletonModifier modifier;
    glm::fmat4 handtrans = glm::identity<glm::mat4>();
    glEnable(GL_DEPTH_TEST);
    //void (*current_hand_motion)(SkeletalMesh::SkeletonModifier& ,glm::fmat4& ,float ,float);
    current_hand_motion = scissor_paper_rock_ready;

    ImGui::CreateContext();
    ImGui_ImplGlfw_InitForOpenGL( window, true );
    ImGui_ImplOpenGL3_Init();
    while (!glfwWindowShouldClose(window)) {
        getKeyInput(window,keys);
        change_camera(camera_eye,camera_center,camera_up);
        passed_time = (float) glfwGetTime();
        // --- You may edit below ---

        // Example: Rotate the hand
        // * turn around every 4 seconds
        //float metacarpals_angle = passed_time * (M_PI / 20.0f);
        //metacarpals_angle = 0.0;
        // * target = metacarpals
        // * rotation axis = (1, 0, 0)
        current_hand_motion(modifier,handtrans,passed_time,motion_start_time);
        //paper_motion(modifier,handtrans,passed_time,0.0);
        draw_ui();
        if(motion_start)
        {
            //printf("spr_state %d\n",spr_state);
            motion_start = false;
            motion_start_time = (float) glfwGetTime();
            if(random_game) spr_state = 1 + rand()%3;
            switch(spr_state)
            {
                case READY:
                    current_hand_motion = scissor_paper_rock_ready;
                    break;
                case SCISSOR:
                    current_hand_motion = scissor_motion;
                    break;
                case PAPER:
                    current_hand_motion = paper_motion;
                    break;
                case ROCK:
                    current_hand_motion = rock_motion;
                    break;
            }
            if(random_game) spr_state = READY;
            if(gun_ready) current_hand_motion = gun_shot_ready;
            if(gun_start) current_hand_motion = gun_shot_motion;
            if(winwin) current_hand_motion = winwin_motion;
            gun_ready = false;
            gun_start = false;
            random_game = false;
            winwin = false;
        }
        //modifier["metacarpals"] = glm::rotate(modifier["metacarpals"], 
        //                                        metacarpals_angle, 
        //                                        glm::fvec3(modifier["metacarpals"]*glm::fvec4(0.0, 0.0, 1.0, 1.0)));
        /**********************************************************************************\
        *
        * To animate fingers, modify modifier["HAND_SECTION"] each frame,
        * where HAND_SECTION can only be one of the bone names in the Hand's Hierarchy.
        *
        * A virtual hand's structure is like this: (slightly DIFFERENT from the real world)
        *    5432 1
        *    ....        1 = thumb           . = fingertip
        *    |||| .      2 = index finger    | = distal phalange
        *    $$$$ |      3 = middle finger   $ = intermediate phalange
        *    #### $      4 = ring finger     # = proximal phalange
        *    OOOO#       5 = pinky           O = metacarpals
        *     OOO
        * (Hand in the real world -> https://en.wikipedia.org/wiki/Hand)
        *
        * From the structure we can infer the Hand's Hierarchy:
        *	- metacarpals
        *		- thumb_proximal_phalange
        *			- thumb_intermediate_phalange
        *				- thumb_distal_phalange
        *					- thumb_fingertip
        *		- index_proximal_phalange
        *			- index_intermediate_phalange
        *				- index_distal_phalange
        *					- index_fingertip
        *		- middle_proximal_phalange
        *			- middle_intermediate_phalange
        *				- middle_distal_phalange
        *					- middle_fingertip
        *		- ring_proximal_phalange
        *			- ring_intermediate_phalange
        *				- ring_distal_phalange
        *					- ring_fingertip
        *		- pinky_proximal_phalange
        *			- pinky_intermediate_phalange
        *				- pinky_distal_phalange
        *					- pinky_fingertip
        *
        * Notice that modifier["HAND_SECTION"] is a local transformation matrix,
        * where (1, 0, 0) is the bone's direction, and apparently (0, 1, 0) / (0, 0, 1)
        * is perpendicular to the bone.
        * Particularly, (0, 0, 1) is the rotation axis of the nearer joint.
        *
        \**********************************************************************************/
        /*
        // Example: Animate the index finger
        // * period = 2.4 seconds
        float period = 2.4f;
        float time_in_period = fmod(passed_time, period);
        // * angle: 0 -> PI/3 -> 0
        float thumb_angle = abs(time_in_period / (period * 0.5f) - 1.0f) * (M_PI / 3.0);
        // * target = proximal phalange of the index
        // * rotation axis = (0, 0, 1)
        modifier["index_proximal_phalange"] = glm::rotate(glm::identity<glm::mat4>(), thumb_angle,
                                                          glm::fvec3(0.0, -10.0, 10.0));
        
        */
        // --- You may edit above ---
        ImGui::Render();
        float ratio;
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        ratio = width / (float) height;

        glClearColor(0.5, 0.5, 0.5, 1.0);

        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glUseProgram(program);
        glm::fmat4 mvp = glm::ortho(-12.5f * ratio, 12.5f * ratio, -5.0f, 20.0f, -20.f, 20.f)
                         *
                         glm::lookAt(camera_eye, camera_center, camera_up)
                         * handtrans;
        glUniformMatrix4fv(glGetUniformLocation(program, "u_mvp"), 1, GL_FALSE, (const GLfloat *) &mvp);
        glUniform1i(glGetUniformLocation(program, "u_diffuse"), SCENE_RESOURCE_SHADER_DIFFUSE_CHANNEL);
        SkeletalMesh::Scene::SkeletonTransf bonesTransf;
        sr.getSkeletonTransform(bonesTransf, modifier);
        if (!bonesTransf.empty())
            glUniformMatrix4fv(glGetUniformLocation(program, "u_bone_transf"), bonesTransf.size(), GL_FALSE,
                               (float *) bonesTransf.data());
        sr.render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    SkeletalMesh::Scene::unloadScene("Hand");

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);

    glfwTerminate();
    exit(EXIT_SUCCESS);
}