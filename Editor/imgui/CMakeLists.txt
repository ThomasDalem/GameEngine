cmake_minimum_required(VERSION 3.23)

set(SRCS
    ${CMAKE_CURRENT_SOURCE_DIR}/src/imgui.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/imgui_demo.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/imgui_draw.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/imgui_impl_sdl2.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/imgui_impl_sdlrenderer2.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/imgui_tables.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/imgui_widgets.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/imgui.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/imconfig.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/imgui_impl_sdl2.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/imgui_impl_sdlrenderer2.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/imgui_internal.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/imstb_rectpack.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/imstb_textedit.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/imstb_truetype.h
)

find_package(SDL2 REQUIRED)

add_library(imgui STATIC ${SRCS})

target_link_libraries(imgui PUBLIC ${SDL2_LIBRARIES})

target_include_directories(imgui
    PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include"
    PRIVATE ${SDL2_INCLUDE_DIRS}
)
