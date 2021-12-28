cmake_minimum_required(VERSION 3.0)

set(project_name irid)

project(${project_name})

set(${project_name}_VERSION_MAJOR 0)
set(${project_name}_VERSION_MINOR 0)
set(${project_name}_VERSION_PATCH 1)

option(BuildIridLibrary "Build Irid static library" ON)
option(BuildIridTest "BuildIridTest" ON)
option(BuildIridDocumentation "BuildIridDocumentation" OFF)
option(BuildIridDemos "BuildIridDemos" ON)

macro(use_c99)
  if(CMAKE_VERSION VERSION_LESS "3.1")
    if(CMAKE_C_COMPILER_ID STREQUAL "GNU")
      set(CMAKE_C_FLAGS "-std=gnu99 ${CMAKE_C_FLAGS}")
    endif()
  else()
    set(CMAKE_C_STANDARD 99)
  endif()
endmacro(use_c99)

use_c99()

if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
  set(OperatingSystem "macos")
  set(contrib_lib_dir ${CMAKE_SOURCE_DIR}/contrib/platform/darwin)
endif()

if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
  set(OperatingSystem "linux")
endif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")

if(WIN32)
  set(OperatingSystem "windows")
endif()

if(${BuildIridTest})
  add_subdirectory(test)
endif()

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH}
                      "${CMAKE_CURRENT_SOURCE_DIR}/cmake/Modules/")

if(CMAKE_BUILD_TYPE)
  if(${CMAKE_BUILD_TYPE} STREQUAL "release")
    set(BuildIridDocumentation ON)
  else()
    set(CMAKE_BUILD_TYPE "debug")
  endif()
else()
  set(CMAKE_BUILD_TYPE "debug")
endif()

message("CMAKE build type:" ${CMAKE_BUILD_TYPE})

message(${project_name})

if(CMAKE_BUILD_TYPE EQUAL "debug")

else()

endif()

if(${have_r4_environment})
  message("Enabling the JSON backend?")
  add_definitions(-DIRID_ENABLE_SERIAL_BACKEND_JSON)

  # set(EnableGPC ON)

endif()

if(BuildIridLibrary)
  message("Adding library target.")
  # if(EnableGPC) set(ext_src src/ext/*.c) else() set(ext_src
  # src/ext/wsh_player.c) endif()

  file(
    GLOB
    sources
    irid.c
    src/output/*.c
    src/core/*.c
    src/util/*.c
    src/decor/*.c
    src/sim/*.c
    ${ext_src}
    # contrib/cjson/cJSON.c
  )
  add_library(${project_name} STATIC ${sources})
  # add_library(wsh SHARED ${sources})
endif()

# if(${have_r4_environment}) message("Building within r4 lib structure.")

# target_include_directories( ${project_name} PUBLIC
# ${CMAKE_CURRENT_SOURCE_DIR}/contrib /opt/X11/include ) else()
# message("Building standalone.") target_include_directories( ${project_name}
# PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/contrib /opt/X11/include )

# macro(use_c99) if(CMAKE_VERSION VERSION_LESS "3.1") if(CMAKE_C_COMPILER_ID
# STREQUAL "GNU") set(CMAKE_C_FLAGS "-std=gnu99 ${CMAKE_C_FLAGS}") endif()
# else() set(CMAKE_C_STANDARD 99) endif() endmacro(use_c99)

# find_package(Doxygen) option(BUILD_DOCUMENTATION "Create and install the HTML
# based API documentation (requires Doxygen)" ${DOXYGEN_FOUND} )

# if(BUILD_DOCUMENTATION) if(BuildWshDocumentation) if(${CMAKE_BUILD_TYPE}
# STREQUAL "release") set(BuildWshDoc YES) endif() endif() endif()

# endif()

# find_package(LibGLFW) include_directories(${LibGLFW_INCLUDE_DIRS}) set(LIBS
# ${LIBS} ${LibGLFW_LIBRARIES})

# if(GLFW_FOUND) if(${CMAKE_BUILD_TYPE} STREQUAL "release") set(BuildIridDemos
# YES) endif()

# else() message("Did not find GLFW, cannot build demo.") set(BuildIridDemo NO)

# endif()

# find_package(LibFTGL) include_directories(${LibGLFW_INCLUDE_DIRS}) set(LIBS
# ${LIBS} ${LibGLFW_LIBRARIES})

# if(FTGL_FOUND) add_definitions(-DWSH_DEMO_ENABLE_FTGL) else() message("Did not
# find FTGL.") endif()

# find_package(LibWCM) include_directories(${LibWCM_INCLUDE_DIRS}) set(LIBS
# ${LIBS} ${LibGWCM_LIBRARIES})

# if(WCM_FOUND) add_definitions(-DWSH_DEMO_ENABLE_WCM) else() message("Did not
# find WCM.") endif()

if(${BuildIridDemos})
  message("Adding demo to build targets.")
  add_subdirectory(demo)
endif()

if(${BuildIridDoc})
  message("Adding documentation to build targets.")

  set(doxyfile_in ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile)
  set(doxyfile ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

  configure_file(${doxyfile_in} ${doxyfile} @ONLY)

  message("Doxygen build started.")
  add_custom_target(
    doc ALL
    COMMAND ${DOXYGEN_EXECUTABLE} ${doxyfile_in}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    COMMENT "Generating API documentation with Doxygen"
    VERBATIM)
endif()

target_include_directories(
  ${project_name} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..
                         ${CMAKE_CURRENT_SOURCE_DIR}/contrib)

# add_custom_command(TARGET ${project_name} POST_BUILD        # Adds a post-
# build event to MyTest COMMAND ${CMAKE_COMMAND} -E copy_if_different  # which
# executes "cmake - E copy_if_different..." "${CMAKE_BINARY_DIR}/libs/${project_
# name}/lib${project_name}${CMAKE_STATIC_LIBRARY_SUFFIX}"      # <--this is in-
# file ${CMAKE_CURRENT_SOURCE_DIR}/lib/osx)                 # <--this is out-
# file path
