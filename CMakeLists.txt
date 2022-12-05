cmake_minimum_required(VERSION 3.21)

project(sys
    VERSION 0.0.0
    LANGUAGES CXX
)

set(ROOT ON)
configure_file(${CMAKE_SOURCE_DIR}/cmake/config.h.cmake ${CMAKE_SOURCE_DIR}/engine/src/Config/config.h)

set(CMAKE_CXX_STANDARD 17)
add_compile_options(-lpthread -lsnappy)

include(engine/engine.cmake)
include(application/application.cmake)
