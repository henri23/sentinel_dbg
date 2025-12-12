#pragma once

#include <memory>
#include <string>

namespace sentinel::core
{
class DebugSession;
class Target;
} // namespace sentinel::core

namespace sentinel::app
{

struct AppConfig
{
    std::string default_target{"demo-target"};
};

class AppContext
{
public:
    explicit AppContext(AppConfig cfg = {});

    std::unique_ptr<core::Target> make_target() const;
    std::unique_ptr<core::DebugSession> make_session() const;

    [[nodiscard]] const AppConfig& config() const noexcept { return config_; }

private:
    AppConfig config_;
};

} // namespace sentinel::app
