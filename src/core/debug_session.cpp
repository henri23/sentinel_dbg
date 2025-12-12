#include "sentinel_dbg/core/debug_session.hpp"

#include "sentinel_dbg/core/target.hpp"

#include <algorithm>
#include <iostream>

namespace sentinel::core
{

DebugSession::DebugSession(std::unique_ptr<Target> target) : target_{std::move(target)} {}
DebugSession::~DebugSession() = default;

void DebugSession::add_breakpoint(Breakpoint bp)
{
    breakpoints_.push_back(std::move(bp));
}

void DebugSession::remove_breakpoint(const std::string& location)
{
    breakpoints_.erase(
        std::remove_if(breakpoints_.begin(), breakpoints_.end(),
                       [&](const Breakpoint& bp) { return bp.location == location; }),
        breakpoints_.end());
}

std::vector<Breakpoint> DebugSession::list_breakpoints() const
{
    return breakpoints_;
}

void DebugSession::run()
{
    if(!target_)
    {
        std::cerr << "No target bound\n";
        return;
    }
    running_ = true;
    target_->attach();
}

void DebugSession::step()
{
    if(!running_)
    {
        std::cerr << "Session not running\n";
        return;
    }
    std::cout << "Stepping target \"" << target_->name() << "\"\n";
}

void DebugSession::stop()
{
    if(!running_)
    {
        return;
    }
    running_ = false;
    if(target_)
    {
        target_->detach();
    }
}

bool DebugSession::is_running() const noexcept
{
    return running_;
}

} // namespace sentinel::core
