cmake_minimum_required(VERSION 3.0)

set(project_name irid_demos)

project(${project_name})

set(${project_name}_VERSION_MAJOR 0)
set(${project_name}_VERSION_MINOR 0)
set(${project_name}_VERSION_PATCH 1)

option(BuildGLFWDemo "Build demo (GLFW)" OFF)
option(BuildSDLDemo "Build demo (SDL2)" OFF)
option(BuildOFDemo "Build demo (Openframeworks)" OFF)

find_package(LibGLFW)
include_directories(${LibGLFW_INCLUDE_DIRS})
set(LIBS ${LIBS} ${LibGLFW_LIBRARIES})

if(GLFW_FOUND)
  set(BuildGLFWDemo YES)
endif()

find_package(LibSDL2)
include_directories(${LiSDL2_INCLUDE_DIRS})
set(LIBS ${LIBS} ${LibSDL2_LIBRARIES})

if(SDL2_FOUND)
  set(BuildSDLDemo YES)
endif()

if(${BuildGLFWDemo})
  message("Adding sdl demo to build targets.")
  add_subdirectory(demo_glfw)
endif()

if(${BuildSDLDemo})
  message("Adding sdl demo to build targets.")
  add_subdirectory(demo_sdl)
endif()

if(${BuildOFDemo})
  message("Adding oF demo to build targets.")
  add_subdirectory(demo_of)
endif()
