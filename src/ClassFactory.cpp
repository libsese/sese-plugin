#include "sese/plugin/Marco.h"
#include "sese/plugin/ClassFactory.h"

sese::plugin::ClassFactory::ClassFactory(const std::initializer_list<sese::plugin::ClassFactory::InitListType> &initializerList) noexcept
    : sese::plugin::BaseClassFactory() {
    for (decltype(auto) pair : initializerList) {
        map.insert(pair);
    }
}

sese::plugin::BaseClass::Ptr sese::plugin::ClassFactory::createClassWithId(const std::string &id) noexcept {
    auto iterator = map.find(id);
    if (iterator != map.end()) {
        return iterator->second();
    } else {
        return nullptr;
    }
}

