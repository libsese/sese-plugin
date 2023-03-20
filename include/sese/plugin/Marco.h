#pragma once

#include "sese/plugin/ModuleInfo.h"

#define DEFINE_MODULE_INFO(name, version, description)     \
    extern "C" sese::plugin::ModuleInfo *getModuleInfo() { \
        static sese::plugin::ModuleInfo info {             \
            name, version, description                     \
        }                                                  \
        return &info;                                      \
    }                                                      \
    while (0)

#define REGISTER_CLASS(id, class)                                           \
    std::pair<std::string, std::function<sese::plugin::BaseClass::Ptr()>> { \
        id, []() -> sese::plugin::BaseClass::Ptr {                          \
            return std::make_shared<class>();                               \
        }                                                                   \
    }

#define DEFINE_CLASS_FACTORY(initList)                       \
    extern "C" sese::plugin::ClassFactory *getFactory() {    \
        static sese::plugin::ClassFactory factory(initList); \
        return &factory;                                     \
    }