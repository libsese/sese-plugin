#pragma once

#include "sese/plugin/BaseClass.h"

#include <string>
#include <functional>
#include <initializer_list>
#include <unordered_map>

namespace sese::plugin {
    class ClassFactory {
    public:
        using InitListType = std::pair<std::string, std::function<std::shared_ptr<BaseClass>()>>;
        using MapType = std::unordered_map<std::string, std::function<std::shared_ptr<BaseClass>()>>;

        ClassFactory(const std::initializer_list<InitListType> &initializerList) noexcept;

        BaseClass::Ptr createClassWithId(const std::string &id) noexcept;

        template<typename Class>
        std::shared_ptr<Class> createClassWithIdAs(const std::string &id) noexcept {
            BaseClass::Ptr baseClass = createClassWithId(id);
            return std::reinterpret_pointer_cast<Class>(baseClass);
        }

    private:
        MapType map;
    };
}// namespace sese::plugin