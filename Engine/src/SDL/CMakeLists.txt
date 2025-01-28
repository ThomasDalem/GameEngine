cmake_minimum_required(VERSION 3.23)

include(GNUInstallDirs)
include(CMakePrintHelpers)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED On)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

set(SRCS
    ${CMAKE_CURRENT_SOURCE_DIR}/src/App.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/App.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Chunk.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Chunk.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Font.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Font.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Renderer.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Renderer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Surface.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Surface.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Texture.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Texture.cpp
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

add_library(sdlabs STATIC ${SRCS})

target_link_libraries(sdlabs PUBLIC utils)

target_include_directories(sdlabs
    PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src"
    PRIVATE ${SDL2_INCLUDE_DIRS}
    PRIVATE ${SDL2_IMAGE_INCLUDE_DIRS}
    PRIVATE ${SDL2_GFX_INCLUDE_DIRS}
    PRIVATE ${SDL2_MIXER_INCLUDE_DIRS}
)
