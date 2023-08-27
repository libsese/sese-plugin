cc_library(
    name = "plugin",
    srcs = ["src/ClassFactory.cpp"],
    hdrs = [
        "include/sese/plugin/BaseClass.h",
        "include/sese/plugin/ClassFactory.h",
        "include/sese/plugin/Marco.h",
        "include/sese/plugin/ModuleInfo.h",
    ],
    copts = select({
        "@platforms//os:windows": [
            "/utf-8",
            "/std:c++17",
        ],
        "//conditions:default": [
            "-std=c++17",
        ],
    }),
    includes = ["include/"],
    visibility = ["//visibility:public"],
)
