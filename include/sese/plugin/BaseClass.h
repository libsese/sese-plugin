#pragma once

#include <memory>

namespace sese::plugin {
    class BaseClass : public std::enable_shared_from_this<BaseClass> {
    public:
        using Ptr = std::shared_ptr<BaseClass>;

        virtual ~BaseClass() = default;
    };
}// namespace sese::plugin