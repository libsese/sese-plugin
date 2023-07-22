add_library(Module SHARED)
target_sources(Module PRIVATE MyModule.cpp)
target_link_libraries(Module PRIVATE Plugin)

if (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    target_compile_options(Module PRIVATE /utf-8)
endif ()