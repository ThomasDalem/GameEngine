cmake_minimum_required(VERSION 3.23)

set(SRCS
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

add_executable(runtime ${SRCS})

target_link_libraries(runtime PUBLIC gengine)
