cmake_minimum_required(VERSION 3.23)

project(gengine VERSION 1.0.0 DESCRIPTION "2D Game Engine")

include(GNUInstallDirs)
include(CMakePrintHelpers)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED On)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

set(SRCS
    ${CMAKE_CURRENT_SOURCE_DIR}/src/systems/RenderSystem.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/systems/AnimationSystem.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/systems/MovementSystem.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/systems/CollisionSystem.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/systems/TilemapSystem.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/engine/Core.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/engine/Scene.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/engine/SoundLoader.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/engine/TexturesLoader.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/engine/TransformUtils.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/engine/WinInfo.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/engine/jsonParse.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/engine/JSONDeserializer.cpp
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

option(BUILD_SHARED_LIBS "Build using shared libraries" ON)

add_library(gengine ${SRCS})

set_target_properties(gengine PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION_MAJOR}
)

configure_file(gengine.pc.in gengine.pc @ONLY)

target_include_directories(gengine
    PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include/"
    #PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include/engine"
    PUBLIC ${SDL2_INCLUDE_DIRS}
    PUBLIC ${SDL2_IMAGE_INCLUDE_DIRS}
    PUBLIC ${SDL2_GFX_INCLUDE_DIRS}
    PUBLIC ${SDL2_MIXER_INCLUDE_DIRS}
)

if (WIN32)
    target_link_libraries(gengine PUBLIC
        ${SDL2_LIBRARIES}
        SDL2::SDL2_image
        SDL2_gfx::SDL2_gfx
        SDL2::SDL2_ttf
        SDL2::Mixer
        Boost::json
        sdlabs utils
    )
else ()
    target_link_libraries(gengine PUBLIC
        ${SDL2_LIBRARIES}
        ${SDL2_IMAGE_LIBRARIES}
        ${SDL2_GFX_LIBRARIES}
        ${SDL2_TTF_LIBRARIES}
        ${SDL2_MIXER_LIBRARIES}
        Boost::json
        sdlabs utils
    )
endif ()

target_sources(gengine
    PUBLIC FILE_SET HEADERS
    BASE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/include
    FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/include/GEngine.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/engine/Core.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/engine/Scene.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/engine/Camera.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/engine/SoundLoader.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/engine/TexturesLoader.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/engine/TransformUtils.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/engine/WinInfo.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/engine/jsonParse.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/engine/JSONDeserializer.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/systems/AnimationSystem.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/systems/CollisionSystem.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/systems/TilemapSystem.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/systems/MovementSystem.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/systems/RenderSystem.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/components/Animation.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/components/Circle.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/components/Collider.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/components/Line.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/components/Movement.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/components/Polygon.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/components/Position.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/components/Rectangle.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/components/Relationship.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/components/Sound.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/components/Sprite.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/components/Tilemap.hpp
)

cmake_print_variables(CMAKE_INSTALL_LIBDIR)
cmake_print_variables(CMAKE_INSTALL_INCLUDEDIR)

install(TARGETS gengine
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}/Engine
    FILE_SET HEADERS DESTINATION include/GEngine
)

install(FILES ${CMAKE_BINARY_DIR}/engine/gengine.pc
    DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig
)
