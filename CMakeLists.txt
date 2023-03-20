cmake_minimum_required(VERSION 3.14)
project(sese.plugin VERSION 0.1)

set(CMAKE_CXX_STANDARD 20)

add_library(Plugin STATIC)

if (WIN32)
    set_target_properties(Plugin PROPERTIES WINDOWS_EXPORT_ALL_SYMBOLS ON)
    target_compile_options(Plugin PRIVATE /utf-8)
endif ()

target_include_directories(
        Plugin
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

target_sources(
        Plugin PRIVATE
        src/ClassFactory.cpp
)