#pragma once

#include "sese/plugin/BaseClass.h"

#include <string>

namespace sese::plugin {
    /// 类工厂基类
    class BaseClassFactory {
    public:
        /// 创建某个已注册类的实例
        /// \param id 类注册名
        virtual BaseClass::Ptr createClassWithId(const std::string &id) noexcept = 0;
    };
}// namespace sese::plugin