add_library(Module SHARED)
target_sources(Module PRIVATE MyModule.cpp)
target_link_libraries(Module PRIVATE Plugin)