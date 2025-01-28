cmake_minimum_required(VERSION 3.23)

project(GameEngine VERSION 1.0.0 DESCRIPTION "2D Game Engine")

set(CMAKE_POSITION_INDEPENDENT_CODE ON)
add_subdirectory("./Editor/imgui")
add_subdirectory("./Engine/src/utils")
add_subdirectory("./Engine/src/SDL")
add_subdirectory("./Engine/")
add_subdirectory("./Editor/common")
add_subdirectory("./Editor/MainEditor")
