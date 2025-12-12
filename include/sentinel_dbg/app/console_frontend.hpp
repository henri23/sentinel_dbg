#pragma once

#include <string>

namespace sentinel::core
{
class CommandRouter;
class DebugSession;
} // namespace sentinel::core

namespace sentinel::app
{

class ConsoleFrontend
{
public:
    ConsoleFrontend(core::CommandRouter& router, core::DebugSession& session);

    void run();

private:
    void print_prompt() const;
    void handle_line(const std::string& line);

    core::CommandRouter& router_;
    core::DebugSession& session_;
    bool active_{true};
};

} // namespace sentinel::app
