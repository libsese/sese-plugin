cmake_minimum_required(VERSION 3.14)
project(sese.plugin VERSION 0.1)

set(CMAKE_CXX_STANDARD 20)

add_library(Plugin STATIC)

if (WIN32)
    set_target_properties(Plugin PROPERTIES WINDOWS_EXPORT_ALL_SYMBOLS ON)
    target_compile_options(Plugin PRIVATE /utf-8)
endif ()

if (CMAKE_SYSTEM_NAME MATCHES "Linux")
    target_compile_options(Plugin PRIVATE -fPIC)
endif()

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

option(SESE_PLUGIN_BUILD_TEST OFF)
if (SESE_PLUGIN_BUILD_TEST)
    add_subdirectory(test)
endif ()

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)
configure_package_config_file(
        ${PROJECT_SOURCE_DIR}/cmake/sese-plugin-config.cmake.in
        ${PROJECT_BINARY_DIR}/sese-plugin-config.cmake
        INSTALL_DESTINATION lib/cmake/sese-plugin
)

install(
        TARGETS Plugin
        EXPORT SesePluginTargets
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        PUBLIC_HEADER DESTINATION include
)

install(
        DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/include/sese"
        DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
)

install(
        FILES "${PROJECT_BINARY_DIR}/sese-plugin-config.cmake"
        DESTINATION lib/cmake/sese-plugin
)

install(
        FILES "${PROJECT_BINARY_DIR}/sese-plugin-config.cmake"
        DESTINATION debug/lib/cmake/sese-plugin
)

install(
        EXPORT SesePluginTargets
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/sese-plugin
        NAMESPACE Sese::
)