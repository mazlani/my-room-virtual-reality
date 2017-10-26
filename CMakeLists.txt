cmake_minimum_required(VERSION 2.8)
# Project Name
PROJECT(demo)
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
if(COMPILER_SUPPORTS_CXX11)
        MESSAGE("CXXFLAGS: ${CMAKE_CXX_FLAGS}")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
        MESSAGE("CXXFLAGS: ${CMAKE_CXX_FLAGS}")

endif()

set(CAVE TRUE)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules")
set(project_LIBRARIES)
set(project_INCLUDES)
set(project_DEFINITIONS)


#########################################################
# ADD PTHREAD
#########################################################
list(APPEND project_LIBRARIES pthread)


set(synch_DIR /sw/synch/latest/cmake)
find_package(synch REQUIRED)
list(APPEND project_LIBRARIES synch )


find_package(GLUT REQUIRED)
list(APPEND project_INCLUDES ${GLUT_INCLUDE_DIR})
list(APPEND project_LIBRARIES ${GLUT_LIBRARIES})


find_package(GLEW REQUIRED)
list(APPEND project_INCLUDES ${GLEW_INCLUDE_DIRS})
list(APPEND project_LIBRARIES ${GLEW_LIBRARIES})

find_package(OpenGL REQUIRED)
list(APPEND project_INCLUDES ${OPENGL_INCLUDE_DIR})
list(APPEND project_LIBRARIES ${OPENGL_LIBRARIES})


#find_package(SDL REQUIRED)
list(APPEND project_INCLUDES "/usr/include/SDL2")
list(APPEND project_LIBRARIES "/usr/lib/x86_64-linux-gnu/libSDL2.so")





#########################################################
# Include Files
#########################################################
include_directories(${CMAKE_SOURCE_DIR} )
include_directories(${project_INCLUDES})
set(HEADERS
)
set(SOURCES
       main.cpp
)




set(HEADERS_SERVER
)

set(SOURCES_SERVER
	main_server.cpp
)




########################################################
# Add definitions
#########################################################
add_definitions(${project_DEFINITIONS})

########################################################
# Linking & stuff
#########################################################




add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
target_link_libraries(${PROJECT_NAME} ${project_LIBRARIES})
add_executable(${PROJECT_NAME}_server ${SOURCES_SERVER} ${HEADERS_SERVER})
target_link_libraries(${PROJECT_NAME}_server ${project_LIBRARIES})

