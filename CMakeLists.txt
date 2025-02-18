cmake_minimum_required(VERSION 3.18)
project(poly-garden VERSION 0.1.0)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_FLAGS "-g3 -O3")

file(GLOB_RECURSE SOURCES
	"./src/*.cc"
	"./src/*.h"
)

add_executable(${PROJECT_NAME} ${SOURCES})

add_subdirectory(libs/glad/)
target_link_libraries(${PROJECT_NAME} PRIVATE glfw glad)
