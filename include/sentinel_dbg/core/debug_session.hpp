#pragma once

#include <memory>
#include <string>
#include <vector>

namespace sentinel::core
{

class Target;

struct Breakpoint
{
    std::string location;
    bool enabled{true};
};

class DebugSession
{
public:
    explicit DebugSession(std::unique_ptr<Target> target);
    ~DebugSession();

    void add_breakpoint(Breakpoint bp);
    void remove_breakpoint(const std::string& location);
    std::vector<Breakpoint> list_breakpoints() const;

    void run();
    void step();
    void stop();

    [[nodiscard]] bool is_running() const noexcept;

private:
    std::unique_ptr<Target> target_;
    std::vector<Breakpoint> breakpoints_;
    bool running_{false};
};

} // namespace sentinel::core
