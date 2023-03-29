#ifndef __HAND_MOTION__
#define __HAND_MOTION__

#include "gl_env.h"
#include <vector>
#include "skeletal_mesh.h"
#include <string>

#include <glm/gtc/matrix_transform.hpp>

enum scissor_paper_rock {READY,SCISSOR,PAPER,ROCK};

float SCISSOR_PAPER_ROCK_ANIMATION_TIME = 0.5f;

float GUN_SHOT_TIME = 0.3f;

float WINWIN_PERIOD = 2.0f;

std::vector<std::string> fringers = {"index","middle","ring","pinky"};
std::vector<std::string> phalange = {"_proximal_phalange","_intermediate_phalange","_distal_phalange"};

void scissor_paper_rock_ready(SkeletalMesh::SkeletonModifier& modifier,glm::fmat4& transmat,float passed_time,float start_time)
{
    modifier["metacarpals"] = glm::rotate(glm::identity<glm::mat4>(), 
                                            float((0.2f)*M_PI), 
                                            glm::fvec3(0.0, 1.0, 0.0));
    transmat = glm::translate(glm::identity<glm::mat4>(), 
                                glm::fvec3(-5.0, 6.0, 0.0));
    modifier["thumb_proximal_phalange"] = glm::rotate(glm::identity<glm::mat4>(),
                                                        float(0.2f*M_PI),
                                                        glm::fvec3(0.0, 0.0, 1.0));
    modifier["thumb_intermediate_phalange"] = glm::rotate(glm::identity<glm::mat4>(),
                                                            float(0.1*M_PI),
                                                            glm::fvec3(0.0, 0.0, 1.0));
    modifier["thumb_distal_phalange"] = glm::rotate(glm::identity<glm::mat4>(),
                                                    float(0.2*M_PI),
                                                    glm::fvec3(0.0, 0.0, 1.0));
    for(int i = 0;i<fringers.size();i++)
    {
        modifier[(fringers[i]+phalange[0]).c_str()] = glm::rotate(glm::identity<glm::mat4>(),
                                                                    float((0.5+0.002*i)*M_PI),
                                                                    glm::fvec3(0.0, 0.0, 1.0));
        for(int j = 1;j<phalange.size();j++)
        {
            modifier[(fringers[i]+phalange[j]).c_str()] = glm::rotate(glm::identity<glm::mat4>(),
                                                                        float((0.52-0.01*j-0.01*i)*M_PI),
                                                                        glm::fvec3(0.0, 0.0, 1.0));
        }
    }
}

void rock_motion(SkeletalMesh::SkeletonModifier& modifier,glm::fmat4& transmat,float passed_time,float start_time)
{
    scissor_paper_rock_ready(modifier,transmat,passed_time,start_time);
    float animation_process = (passed_time - start_time)/SCISSOR_PAPER_ROCK_ANIMATION_TIME;
    if(animation_process>1) animation_process = 1.0f;
    modifier["metacarpals"] = glm::rotate(glm::identity<glm::mat4>(), 
                                            float((0.2f+0.2f*animation_process)*M_PI), 
                                            glm::fvec3(0.0, 1.0, 0.0));
}

void scissor_motion(SkeletalMesh::SkeletonModifier& modifier,glm::fmat4& transmat,float passed_time,float start_time)
{
    scissor_paper_rock_ready(modifier,transmat,passed_time,start_time);
    float animation_process = (passed_time - start_time)/SCISSOR_PAPER_ROCK_ANIMATION_TIME;
    if(animation_process>1) animation_process = 1.0f;
    modifier["metacarpals"] = glm::rotate(glm::identity<glm::mat4>(), 
                                            float((0.2f+0.2f*animation_process)*M_PI), 
                                            glm::fvec3(0.0, 1.0, 0.0));
    modifier["thumb_intermediate_phalange"] = glm::rotate(glm::identity<glm::mat4>(),
                                                            float(0.1*(1-1.5*animation_process)*M_PI),
                                                            glm::fvec3(0.0, 0.0, 1.0));
    modifier["thumb_distal_phalange"] = glm::rotate(glm::identity<glm::mat4>(),
                                                    float(0.2*(1-1.5*animation_process)*M_PI),
                                                    glm::fvec3(0.0, 0.0, 1.0));
    for(int i = 0;i<fringers.size()-2;i++)
    {
        modifier[(fringers[i]+phalange[0]).c_str()] = glm::rotate(glm::identity<glm::mat4>(),
                                                                    float((0.5+0.002*i)*(1-1.05*animation_process)*M_PI),
                                                                    glm::fvec3(0.0, 0.0, 1.0));
        modifier[(fringers[i]+phalange[0]).c_str()] = glm::rotate(modifier[(fringers[i]+phalange[0]).c_str()],
                                                                    float(-0.02*(1-i)*animation_process*M_PI),
                                                                    glm::fvec3(0.0, 1.0, 0.0));
        for(int j = 1;j<phalange.size();j++)
        {
            modifier[(fringers[i]+phalange[j]).c_str()] = glm::rotate(glm::identity<glm::mat4>(),
                                                                        float((0.52-0.01*j-0.01*i)*(1-1.1*animation_process)*M_PI),
                                                                        glm::fvec3(0.0, 0.0, 1.0));
        }
    }
}

void paper_motion(SkeletalMesh::SkeletonModifier& modifier,glm::fmat4& transmat,float passed_time,float start_time)
{
    scissor_paper_rock_ready(modifier,transmat,passed_time,start_time);
    float animation_process = (passed_time - start_time)/SCISSOR_PAPER_ROCK_ANIMATION_TIME;
    if(animation_process>1) animation_process = 1.0f;
    modifier["metacarpals"] = glm::rotate(glm::identity<glm::mat4>(), 
                                            float((0.2f+0.2f*animation_process)*M_PI), 
                                            glm::fvec3(0.0, 1.0, 0.0));
    modifier["thumb_proximal_phalange"] = glm::rotate(glm::identity<glm::mat4>(),
                                                        float(0.2f*(1-animation_process)*M_PI),
                                                        glm::fvec3(0.0, 0.0, 1.0));
    modifier["thumb_proximal_phalange"] = glm::rotate(modifier["thumb_proximal_phalange"],
                                                        float(0.2*animation_process*M_PI),
                                                        glm::fvec3(0.0, 1.0, 0.0));
    modifier["thumb_intermediate_phalange"] = glm::rotate(glm::identity<glm::mat4>(),
                                                            float(0.1*(1-1.5*animation_process)*M_PI),
                                                            glm::fvec3(0.0, 0.0, 1.0));
    modifier["thumb_distal_phalange"] = glm::rotate(glm::identity<glm::mat4>(),
                                                    float(0.2*(1-1.5*animation_process)*M_PI),
                                                    glm::fvec3(0.0, 0.0, 1.0));
    for(int i = 0;i<fringers.size();i++)
    {
        modifier[(fringers[i]+phalange[0]).c_str()] = glm::rotate(glm::identity<glm::mat4>(),
                                                                    float((0.5+0.002*i)*(1-1.05*animation_process)*M_PI),
                                                                    glm::fvec3(0.0, 0.0, 1.0));
        for(int j = 1;j<phalange.size();j++)
        {
            modifier[(fringers[i]+phalange[j]).c_str()] = glm::rotate(glm::identity<glm::mat4>(),
                                                                        float((0.52-0.01*j-0.01*i)*(1-1.1*animation_process)*M_PI),
                                                                        glm::fvec3(0.0, 0.0, 1.0));
        }
    }
}

void gun_shot_ready(SkeletalMesh::SkeletonModifier& modifier, glm::fmat4& transmat, float passed_time, float start_time)
{
    transmat = glm::translate(glm::identity<glm::mat4>(), 
                                glm::fvec3(-5.0, 6.0, 0.0));
    modifier["metacarpals"] = glm::rotate(glm::identity<glm::mat4>(), 
                                            float((0.5f)*M_PI), 
                                            glm::fvec3(0.0, 1.0, 0.0));
    modifier["thumb_proximal_phalange"] = glm::rotate(glm::identity<glm::mat4>(),
                                                        float(0.0f*M_PI),
                                                        glm::fvec3(0.0, 0.0, 1.0));
    modifier["thumb_proximal_phalange"] = glm::rotate(modifier["thumb_proximal_phalange"],
                                                        float(0.2f*M_PI),
                                                        glm::fvec3(0.0, 1.0, 0.0));
    modifier["thumb_intermediate_phalange"] = glm::rotate(glm::identity<glm::mat4>(),
                                                            float(-0.05f*M_PI),
                                                            glm::fvec3(0.0, 0.0, 1.0));
    modifier["thumb_distal_phalange"] = glm::rotate(glm::identity<glm::mat4>(),
                                                    float(-0.1f*M_PI),
                                                    glm::fvec3(0.0, 0.0, 1.0));
    for(int i = 0;i<fringers.size()-2;i++)
    {
        modifier[(fringers[i]+phalange[0]).c_str()] = glm::rotate(glm::identity<glm::mat4>(),
                                                                    float(-0.01f*M_PI),
                                                                    glm::fvec3(0.0, 0.0, 1.0));
        modifier[(fringers[i]+phalange[0]).c_str()] = glm::rotate(modifier[(fringers[i]+phalange[0]).c_str()],
                                                                    float(0.02f*(1-2*i)*M_PI),
                                                                    glm::fvec3(0.0, 1.0, 0.0));
        for(int j = 1;j<phalange.size();j++)
        {
            modifier[(fringers[i]+phalange[j]).c_str()] = glm::rotate(glm::identity<glm::mat4>(),
                                                                        float(-0.01f*M_PI),
                                                                        glm::fvec3(0.0, 0.0, 1.0));
        }
    }
    for(int i = 2;i<fringers.size();i++)
    {
        modifier[(fringers[i]+phalange[0]).c_str()] = glm::rotate(glm::identity<glm::mat4>(),
                                                                    float((0.5+0.002*i)*M_PI),
                                                                    glm::fvec3(0.0, 0.0, 1.0));
        for(int j = 1;j<phalange.size();j++)
        {
            modifier[(fringers[i]+phalange[j]).c_str()] = glm::rotate(glm::identity<glm::mat4>(),
                                                                        float((0.52-0.01*j-0.01*i)*M_PI),
                                                                        glm::fvec3(0.0, 0.0, 1.0));
        }
    }
}

void gun_shot_motion(SkeletalMesh::SkeletonModifier& modifier, glm::fmat4& transmat, float passed_time, float start_time)
{
    float motion_process = (passed_time - start_time)/GUN_SHOT_TIME;
    if(motion_process>1) motion_process = 1.0f;
    modifier["metacarpals"] = glm::rotate(glm::identity<glm::mat4>(), 
                                            float((0.5f)*(1-0.5*motion_process)*M_PI), 
                                            glm::fvec3(0.0, 1.0, 0.0));
    transmat = glm::translate(glm::identity<glm::mat4>(), 
                                glm::fvec3(-5.0, 6.0, 0.0));
    modifier["thumb_proximal_phalange"] = glm::rotate(glm::identity<glm::mat4>(),
                                                        float(0.0f*M_PI),
                                                        glm::fvec3(0.0, 0.0, 1.0));
    modifier["thumb_proximal_phalange"] = glm::rotate(modifier["thumb_proximal_phalange"],
                                                        float(0.2f*M_PI),
                                                        glm::fvec3(0.0, 1.0, 0.0));
    modifier["thumb_intermediate_phalange"] = glm::rotate(glm::identity<glm::mat4>(),
                                                            float(-0.05f*M_PI),
                                                            glm::fvec3(0.0, 0.0, 1.0));
    modifier["thumb_distal_phalange"] = glm::rotate(glm::identity<glm::mat4>(),
                                                    float(-0.1f*M_PI),
                                                    glm::fvec3(0.0, 0.0, 1.0));
    for(int i = 0;i<fringers.size()-2;i++)
    {
        modifier[(fringers[i]+phalange[0]).c_str()] = glm::rotate(glm::identity<glm::mat4>(),
                                                                    float(-0.01f*M_PI),
                                                                    glm::fvec3(0.0, 0.0, 1.0));
        modifier[(fringers[i]+phalange[0]).c_str()] = glm::rotate(modifier[(fringers[i]+phalange[0]).c_str()],
                                                                    float(0.02f*(1-2*i)*M_PI),
                                                                    glm::fvec3(0.0, 1.0, 0.0));
        for(int j = 1;j<phalange.size();j++)
        {
            modifier[(fringers[i]+phalange[j]).c_str()] = glm::rotate(glm::identity<glm::mat4>(),
                                                                        float(-0.01f*M_PI),
                                                                        glm::fvec3(0.0, 0.0, 1.0));
        }
    }
    for(int i = 2;i<fringers.size();i++)
    {
        modifier[(fringers[i]+phalange[0]).c_str()] = glm::rotate(glm::identity<glm::mat4>(),
                                                                    float((0.5+0.002*i)*M_PI),
                                                                    glm::fvec3(0.0, 0.0, 1.0));
        for(int j = 1;j<phalange.size();j++)
        {
            modifier[(fringers[i]+phalange[j]).c_str()] = glm::rotate(glm::identity<glm::mat4>(),
                                                                        float((0.52-0.01*j-0.01*i)*M_PI),
                                                                        glm::fvec3(0.0, 0.0, 1.0));
        }
    }
}

float tri_map(float x)
{
    if(x<0) return x;
    else return -x;
}

void winwin_motion(SkeletalMesh::SkeletonModifier& modifier, glm::fmat4& transmat, float passed_time, float start_time)
{
    float animation_process = (passed_time - start_time)/WINWIN_PERIOD;
    while(animation_process>1) animation_process -= 1.0f;
    modifier["metacarpals"] = glm::rotate(glm::identity<glm::mat4>(), 
                                            float((0.2f)*(1+4*tri_map(animation_process-0.5))*M_PI), 
                                            glm::fvec3(0.0, 1.0, 0.0));
    transmat = glm::translate(glm::identity<glm::mat4>(), 
                                glm::fvec3(0.0, 3.0, 0.0));
    modifier["thumb_proximal_phalange"] = glm::rotate(glm::identity<glm::mat4>(),
                                                        float(-0.1f*M_PI),
                                                        glm::fvec3(0.0, 0.0, 1.0));
    modifier["thumb_proximal_phalange"] = glm::rotate(modifier["thumb_proximal_phalange"],
                                                        float(0.2*M_PI),
                                                        glm::fvec3(0.0, 1.0, 0.0));
    modifier["thumb_intermediate_phalange"] = glm::rotate(glm::identity<glm::mat4>(),
                                                            float(-0.1*M_PI),
                                                            glm::fvec3(0.0, 0.0, 1.0));
    modifier["thumb_distal_phalange"] = glm::rotate(glm::identity<glm::mat4>(),
                                                    float(-0.1*M_PI),
                                                    glm::fvec3(0.0, 0.0, 1.0));
    for(int i = 0;i<fringers.size()-1;i++)
    {
        modifier[(fringers[i]+phalange[0]).c_str()] = glm::rotate(glm::identity<glm::mat4>(),
                                                                    float((0.5+0.002*i)*M_PI),
                                                                    glm::fvec3(0.0, 0.0, 1.0));
        modifier[(fringers[i]+phalange[0]).c_str()] = glm::rotate(modifier[(fringers[i]+phalange[0]).c_str()],
                                                                    float(-0.02*(2-i)*M_PI),
                                                                    glm::fvec3(0.0, 1.0, 0.0));                                                     
        for(int j = 1;j<phalange.size();j++)
        {
            modifier[(fringers[i]+phalange[j]).c_str()] = glm::rotate(glm::identity<glm::mat4>(),
                                                                        float((0.52-0.08*j-0.01*i)*M_PI),
                                                                        glm::fvec3(0.0, 0.0, 1.0));
        }
    }
    modifier["pinky_proximal_phalange"] = glm::rotate(glm::identity<glm::mat4>(),
                                                        float(0.1*M_PI),
                                                        glm::fvec3(0.0, 0.0, 1.0));
    for(int j = 1;j<phalange.size();j++)
    {
        modifier[("pinky" + phalange[j]).c_str()] = glm::rotate(glm::identity<glm::mat4>(),
                                                                    float(-0.05*M_PI),
                                                                    glm::fvec3(0.0, 0.0, 1.0));
    }
}
#endif