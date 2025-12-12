#pragma once

#include <string>

namespace sentinel::core
{

class Target
{
public:
    explicit Target(std::string name) : name_{std::move(name)} {}

    void attach();
    void detach();
    [[nodiscard]] std::string_view name() const noexcept { return name_; }

private:
    std::string name_;
    bool attached_{false};
};

} // namespace sentinel::core
