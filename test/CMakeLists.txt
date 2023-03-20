add_library(Module SHARED)
target_sources(Module PRIVATE MyModule.cpp)
target_link_libraries(Module PRIVATE Plugin)

if (WIN32)
    target_compile_options(Module PRIVATE /utf-8)
endif ()