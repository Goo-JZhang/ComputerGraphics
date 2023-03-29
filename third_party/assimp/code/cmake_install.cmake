# Install script for directory: /home/zjlwsl/project/computer_graphics/Hand-cmake/hand-graphics-homework-main/third_party/assimp/code

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/zjlwsl/project/computer_graphics/Hand-cmake/hand-graphics-homework-main/lib/libassimp.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xassimp-devx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/assimp" TYPE FILE FILES
    "/home/zjlwsl/project/computer_graphics/Hand-cmake/hand-graphics-homework-main/third_party/assimp/code/../include/assimp/anim.h"
    "/home/zjlwsl/project/computer_graphics/Hand-cmake/hand-graphics-homework-main/third_party/assimp/code/../include/assimp/aabb.h"
    "/home/zjlwsl/project/computer_graphics/Hand-cmake/hand-graphics-homework-main/third_party/assimp/code/../include/assimp/ai_assert.h"
    "/home/zjlwsl/project/computer_graphics/Hand-cmake/hand-graphics-homework-main/third_party/assimp/code/../include/assimp/camera.h"
    "/home/zjlwsl/project/computer_graphics/Hand-cmake/hand-graphics-homework-main/third_party/assimp/code/../include/assimp/color4.h"
    "/home/zjlwsl/project/computer_graphics/Hand-cmake/hand-graphics-homework-main/third_party/assimp/code/../include/assimp/color4.inl"
    "/home/zjlwsl/project/computer_graphics/Hand-cmake/hand-graphics-homework-main/third_party/assimp/code/../include/assimp/config.h"
    "/home/zjlwsl/project/computer_graphics/Hand-cmake/hand-graphics-homework-main/third_party/assimp/code/../include/assimp/defs.h"
    "/home/zjlwsl/project/computer_graphics/Hand-cmake/hand-graphics-homework-main/third_party/assimp/code/../include/assimp/Defines.h"
    "/home/zjlwsl/project/computer_graphics/Hand-cmake/hand-graphics-homework-main/third_party/assimp/code/../include/assimp/cfileio.h"
    "/home/zjlwsl/project/computer_graphics/Hand-cmake/hand-graphics-homework-main/third_party/assimp/code/../include/assimp/light.h"
    "/home/zjlwsl/project/computer_graphics/Hand-cmake/hand-graphics-homework-main/third_party/assimp/code/../include/assimp/material.h"
    "/home/zjlwsl/project/computer_graphics/Hand-cmake/hand-graphics-homework-main/third_party/assimp/code/../include/assimp/material.inl"
    "/home/zjlwsl/project/computer_graphics/Hand-cmake/hand-graphics-homework-main/third_party/assimp/code/../include/assimp/matrix3x3.h"
    "/home/zjlwsl/project/computer_graphics/Hand-cmake/hand-graphics-homework-main/third_party/assimp/code/../include/assimp/matrix3x3.inl"
    "/home/zjlwsl/project/computer_graphics/Hand-cmake/hand-graphics-homework-main/third_party/assimp/code/../include/assimp/matrix4x4.h"
    "/home/zjlwsl/project/computer_graphics/Hand-cmake/hand-graphics-homework-main/third_party/assimp/code/../include/assimp/matrix4x4.inl"
    "/home/zjlwsl/project/computer_graphics/Hand-cmake/hand-graphics-homework-main/third_party/assimp/code/../include/assimp/mesh.h"
    "/home/zjlwsl/project/computer_graphics/Hand-cmake/hand-graphics-homework-main/third_party/assimp/code/../include/assimp/pbrmaterial.h"
    "/home/zjlwsl/project/computer_graphics/Hand-cmake/hand-graphics-homework-main/third_party/assimp/code/../include/assimp/postprocess.h"
    "/home/zjlwsl/project/computer_graphics/Hand-cmake/hand-graphics-homework-main/third_party/assimp/code/../include/assimp/quaternion.h"
    "/home/zjlwsl/project/computer_graphics/Hand-cmake/hand-graphics-homework-main/third_party/assimp/code/../include/assimp/quaternion.inl"
    "/home/zjlwsl/project/computer_graphics/Hand-cmake/hand-graphics-homework-main/third_party/assimp/code/../include/assimp/scene.h"
    "/home/zjlwsl/project/computer_graphics/Hand-cmake/hand-graphics-homework-main/third_party/assimp/code/../include/assimp/metadata.h"
    "/home/zjlwsl/project/computer_graphics/Hand-cmake/hand-graphics-homework-main/third_party/assimp/code/../include/assimp/texture.h"
    "/home/zjlwsl/project/computer_graphics/Hand-cmake/hand-graphics-homework-main/third_party/assimp/code/../include/assimp/types.h"
    "/home/zjlwsl/project/computer_graphics/Hand-cmake/hand-graphics-homework-main/third_party/assimp/code/../include/assimp/vector2.h"
    "/home/zjlwsl/project/computer_graphics/Hand-cmake/hand-graphics-homework-main/third_party/assimp/code/../include/assimp/vector2.inl"
    "/home/zjlwsl/project/computer_graphics/Hand-cmake/hand-graphics-homework-main/third_party/assimp/code/../include/assimp/vector3.h"
    "/home/zjlwsl/project/computer_graphics/Hand-cmake/hand-graphics-homework-main/third_party/assimp/code/../include/assimp/vector3.inl"
    "/home/zjlwsl/project/computer_graphics/Hand-cmake/hand-graphics-homework-main/third_party/assimp/code/../include/assimp/version.h"
    "/home/zjlwsl/project/computer_graphics/Hand-cmake/hand-graphics-homework-main/third_party/assimp/code/../include/assimp/cimport.h"
    "/home/zjlwsl/project/computer_graphics/Hand-cmake/hand-graphics-homework-main/third_party/assimp/code/../include/assimp/importerdesc.h"
    "/home/zjlwsl/project/computer_graphics/Hand-cmake/hand-graphics-homework-main/third_party/assimp/code/../include/assimp/Importer.hpp"
    "/home/zjlwsl/project/computer_graphics/Hand-cmake/hand-graphics-homework-main/third_party/assimp/code/../include/assimp/DefaultLogger.hpp"
    "/home/zjlwsl/project/computer_graphics/Hand-cmake/hand-graphics-homework-main/third_party/assimp/code/../include/assimp/ProgressHandler.hpp"
    "/home/zjlwsl/project/computer_graphics/Hand-cmake/hand-graphics-homework-main/third_party/assimp/code/../include/assimp/IOStream.hpp"
    "/home/zjlwsl/project/computer_graphics/Hand-cmake/hand-graphics-homework-main/third_party/assimp/code/../include/assimp/IOSystem.hpp"
    "/home/zjlwsl/project/computer_graphics/Hand-cmake/hand-graphics-homework-main/third_party/assimp/code/../include/assimp/Logger.hpp"
    "/home/zjlwsl/project/computer_graphics/Hand-cmake/hand-graphics-homework-main/third_party/assimp/code/../include/assimp/LogStream.hpp"
    "/home/zjlwsl/project/computer_graphics/Hand-cmake/hand-graphics-homework-main/third_party/assimp/code/../include/assimp/NullLogger.hpp"
    "/home/zjlwsl/project/computer_graphics/Hand-cmake/hand-graphics-homework-main/third_party/assimp/code/../include/assimp/cexport.h"
    "/home/zjlwsl/project/computer_graphics/Hand-cmake/hand-graphics-homework-main/third_party/assimp/code/../include/assimp/Exporter.hpp"
    "/home/zjlwsl/project/computer_graphics/Hand-cmake/hand-graphics-homework-main/third_party/assimp/code/../include/assimp/DefaultIOStream.h"
    "/home/zjlwsl/project/computer_graphics/Hand-cmake/hand-graphics-homework-main/third_party/assimp/code/../include/assimp/DefaultIOSystem.h"
    "/home/zjlwsl/project/computer_graphics/Hand-cmake/hand-graphics-homework-main/third_party/assimp/code/../include/assimp/ZipArchiveIOSystem.h"
    "/home/zjlwsl/project/computer_graphics/Hand-cmake/hand-graphics-homework-main/third_party/assimp/code/../include/assimp/SceneCombiner.h"
    "/home/zjlwsl/project/computer_graphics/Hand-cmake/hand-graphics-homework-main/third_party/assimp/code/../include/assimp/fast_atof.h"
    "/home/zjlwsl/project/computer_graphics/Hand-cmake/hand-graphics-homework-main/third_party/assimp/code/../include/assimp/qnan.h"
    "/home/zjlwsl/project/computer_graphics/Hand-cmake/hand-graphics-homework-main/third_party/assimp/code/../include/assimp/BaseImporter.h"
    "/home/zjlwsl/project/computer_graphics/Hand-cmake/hand-graphics-homework-main/third_party/assimp/code/../include/assimp/Hash.h"
    "/home/zjlwsl/project/computer_graphics/Hand-cmake/hand-graphics-homework-main/third_party/assimp/code/../include/assimp/MemoryIOWrapper.h"
    "/home/zjlwsl/project/computer_graphics/Hand-cmake/hand-graphics-homework-main/third_party/assimp/code/../include/assimp/ParsingUtils.h"
    "/home/zjlwsl/project/computer_graphics/Hand-cmake/hand-graphics-homework-main/third_party/assimp/code/../include/assimp/StreamReader.h"
    "/home/zjlwsl/project/computer_graphics/Hand-cmake/hand-graphics-homework-main/third_party/assimp/code/../include/assimp/StreamWriter.h"
    "/home/zjlwsl/project/computer_graphics/Hand-cmake/hand-graphics-homework-main/third_party/assimp/code/../include/assimp/StringComparison.h"
    "/home/zjlwsl/project/computer_graphics/Hand-cmake/hand-graphics-homework-main/third_party/assimp/code/../include/assimp/StringUtils.h"
    "/home/zjlwsl/project/computer_graphics/Hand-cmake/hand-graphics-homework-main/third_party/assimp/code/../include/assimp/SGSpatialSort.h"
    "/home/zjlwsl/project/computer_graphics/Hand-cmake/hand-graphics-homework-main/third_party/assimp/code/../include/assimp/GenericProperty.h"
    "/home/zjlwsl/project/computer_graphics/Hand-cmake/hand-graphics-homework-main/third_party/assimp/code/../include/assimp/SpatialSort.h"
    "/home/zjlwsl/project/computer_graphics/Hand-cmake/hand-graphics-homework-main/third_party/assimp/code/../include/assimp/SkeletonMeshBuilder.h"
    "/home/zjlwsl/project/computer_graphics/Hand-cmake/hand-graphics-homework-main/third_party/assimp/code/../include/assimp/SmoothingGroups.h"
    "/home/zjlwsl/project/computer_graphics/Hand-cmake/hand-graphics-homework-main/third_party/assimp/code/../include/assimp/SmoothingGroups.inl"
    "/home/zjlwsl/project/computer_graphics/Hand-cmake/hand-graphics-homework-main/third_party/assimp/code/../include/assimp/StandardShapes.h"
    "/home/zjlwsl/project/computer_graphics/Hand-cmake/hand-graphics-homework-main/third_party/assimp/code/../include/assimp/RemoveComments.h"
    "/home/zjlwsl/project/computer_graphics/Hand-cmake/hand-graphics-homework-main/third_party/assimp/code/../include/assimp/Subdivision.h"
    "/home/zjlwsl/project/computer_graphics/Hand-cmake/hand-graphics-homework-main/third_party/assimp/code/../include/assimp/Vertex.h"
    "/home/zjlwsl/project/computer_graphics/Hand-cmake/hand-graphics-homework-main/third_party/assimp/code/../include/assimp/LineSplitter.h"
    "/home/zjlwsl/project/computer_graphics/Hand-cmake/hand-graphics-homework-main/third_party/assimp/code/../include/assimp/TinyFormatter.h"
    "/home/zjlwsl/project/computer_graphics/Hand-cmake/hand-graphics-homework-main/third_party/assimp/code/../include/assimp/Profiler.h"
    "/home/zjlwsl/project/computer_graphics/Hand-cmake/hand-graphics-homework-main/third_party/assimp/code/../include/assimp/LogAux.h"
    "/home/zjlwsl/project/computer_graphics/Hand-cmake/hand-graphics-homework-main/third_party/assimp/code/../include/assimp/Bitmap.h"
    "/home/zjlwsl/project/computer_graphics/Hand-cmake/hand-graphics-homework-main/third_party/assimp/code/../include/assimp/XMLTools.h"
    "/home/zjlwsl/project/computer_graphics/Hand-cmake/hand-graphics-homework-main/third_party/assimp/code/../include/assimp/IOStreamBuffer.h"
    "/home/zjlwsl/project/computer_graphics/Hand-cmake/hand-graphics-homework-main/third_party/assimp/code/../include/assimp/CreateAnimMesh.h"
    "/home/zjlwsl/project/computer_graphics/Hand-cmake/hand-graphics-homework-main/third_party/assimp/code/../include/assimp/irrXMLWrapper.h"
    "/home/zjlwsl/project/computer_graphics/Hand-cmake/hand-graphics-homework-main/third_party/assimp/code/../include/assimp/BlobIOSystem.h"
    "/home/zjlwsl/project/computer_graphics/Hand-cmake/hand-graphics-homework-main/third_party/assimp/code/../include/assimp/MathFunctions.h"
    "/home/zjlwsl/project/computer_graphics/Hand-cmake/hand-graphics-homework-main/third_party/assimp/code/../include/assimp/Macros.h"
    "/home/zjlwsl/project/computer_graphics/Hand-cmake/hand-graphics-homework-main/third_party/assimp/code/../include/assimp/Exceptional.h"
    "/home/zjlwsl/project/computer_graphics/Hand-cmake/hand-graphics-homework-main/third_party/assimp/code/../include/assimp/ByteSwapper.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xassimp-devx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/assimp/Compiler" TYPE FILE FILES
    "/home/zjlwsl/project/computer_graphics/Hand-cmake/hand-graphics-homework-main/third_party/assimp/code/../include/assimp/Compiler/pushpack1.h"
    "/home/zjlwsl/project/computer_graphics/Hand-cmake/hand-graphics-homework-main/third_party/assimp/code/../include/assimp/Compiler/poppack1.h"
    "/home/zjlwsl/project/computer_graphics/Hand-cmake/hand-graphics-homework-main/third_party/assimp/code/../include/assimp/Compiler/pstdint.h"
    )
endif()

