#pragma once

#include "sese/plugin/ModuleInfo.h"

#ifdef WIN32
#define SESE_EXTERN extern "C" __declspec(dllexport)
#else
#define SESE_EXTERN extern "C"
#endif

#define DEFINE_MODULE_INFO(name, version, description)                    \
    SESE_EXTERN sese::plugin::ModuleInfo *getModuleInfo() {               \
        static sese::plugin::ModuleInfo info{name, version, description}; \
        return &info;                                                     \
    }

#define REGISTER_CLASS(id, class)                                           \
    std::pair<std::string, std::function<sese::plugin::BaseClass::Ptr()>> { \
        id, []() -> sese::plugin::BaseClass::Ptr {                          \
            return std::make_shared<class>();                               \
        }                                                                   \
    }

#define DEFINE_CLASS_FACTORY(...)                                 \
    SESE_EXTERN sese::plugin::BaseClassFactory *getFactory() {    \
        static sese::plugin::ClassFactory factory({__VA_ARGS__}); \
        return &factory;                                          \
    }