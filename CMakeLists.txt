cmake_minimum_required(VERSION 3.23)

project(GameEngine VERSION 1.0.0 DESCRIPTION "2D Game Engine")

option(BUILD_IMGUI "Enable building imgui" ON)
option(BUILD_ENGINE "Enable building Engine" ON)
option(BUILD_EDITOR "Enable building Editor" ON)

if(BUILD_IMGUI)
    add_subdirectory("./Editor/imgui")
endif()
if(BUILD_ENGINE)
    add_subdirectory("./Engine")
endif()
if(BUILD_EDITOR)
    add_subdirectory("./Editor/Common")
    add_subdirectory("./Editor/MainEditor")
endif()
