cc_library(
    name = "MyModule",
    srcs = ["MyModule.cpp"],
    copts = select({
        "@platforms//os:windows": [
            "/utf-8",
            "/std:c++20",
        ],
        "//conditions:default": [
            "-std=c++20",
        ],
    }),
    deps = ["@com_sese_plugin//:plugin"],
)
