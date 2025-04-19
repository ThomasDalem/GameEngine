cmake_minimum_required(VERSION 3.23)

include(GNUInstallDirs)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED On)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

set(SRCS
    src/main.cpp
    src/Core.cpp
    src/build.cpp
)

set(HEADERS
    src/Core.hpp
    src/build.hpp
)

if (MSVC)
    # warning level 4
    add_compile_options(/W4)
else()
    # additional warnings
    add_compile_options(-Wall -Wextra -Wpedantic -g)
endif()

if (WIN32)
    set(PNG_LIBRARY "C:/Users/Thomas/vcpkg/packages/libpng_x64-windows/lib")
    set(PNG_PNG_INCLUDE_DIR "C:/Users/Thomas/vcpkg/packages/libpng_x64-windows/include")
    set(ZLIB_LIBRARY "C:/Users/Thomas/vcpkg/packages/zlib_x64-windows/lib")
    set(ZLIB_INCLUDE_DIR "C:/Users/Thomas/vcpkg/packages/zlib_x64-windows/include")
endif ()

if (WIN32)
    set(SDL2_image_DIR "C:/Users/Thomas/vcpkg/packages/sdl2-image_x64-windows/share/SDL2_image")
endif ()

find_package(Boost 1.86 REQUIRED COMPONENTS json)
find_package(OpenGL REQUIRED)

if (WIN32)
    find_package(sdl2 CONFIG REQUIRED)
    find_package(SDL2_image CONFIG REQUIRED)
    find_package(sdl2-gfx CONFIG REQUIRED)
    find_package(sdl2-ttf CONFIG REQUIRED)
    find_package(SDL2_mixer REQUIRED)
else ()
    find_package(SDL2 REQUIRED)
    find_package(SDL2_image REQUIRED)
    find_package(SDL2_gfx REQUIRED)
    find_package(SDL2_ttf REQUIRED)
    find_package(SDL2_mixer REQUIRED)
endif ()

add_executable(Editor ${SRCS} ${HEADERS})

if (WIN32)
    target_link_libraries(Editor PUBLIC
        ${SDL2_LIBRARIES}
        SDL2::SDL2_image
        SDL2_gfx::SDL2_gfx
        SDL2::SDL2_ttf
        SDL2::Mixer
        Boost::json
        imgui
        sdlabs
        OpenGL
    )
else ()
    target_link_libraries(Editor PUBLIC 
        ${SDL2_LIBRARIES}
        ${SDL2_IMAGE_LIBRARIES}
        ${SDL2_GFX_LIBRARIES}
        ${SDL2_TTF_LIBRARIES}
        ${SDL2_MIXER_LIBRARIES}
        Boost::json
        imgui
        sdlabs
        OpenGL
    )
endif ()

target_include_directories(Editor
    PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src"
    PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include"
    PUBLIC ${SDL2_INCLUDE_DIRS}
    PUBLIC ${SDL2_IMAGE_INCLUDE_DIRS}
    PUBLIC ${SDL2_GFX_INCLUDE_DIRS}
    PUBLIC ${SDL2_MIXER_INCLUDE_DIRS}
    PUBLIC ${OPENGL_INCLUDE_DIRS}
)
