#pragma once

#include "sese/plugin/ClassFactory.h"

namespace sese::plugin {
    struct ModuleInfo {
        const char *moduleName;
        const char *versionString;
        const char *description;
    };
}// namespace sese::plugin
