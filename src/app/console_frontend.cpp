#include "sentinel_dbg/app/console_frontend.hpp"

#include "sentinel_dbg/core/command_router.hpp"
#include "sentinel_dbg/core/debug_session.hpp"

#include <iostream>
#include <string>

namespace sentinel::app
{

ConsoleFrontend::ConsoleFrontend(core::CommandRouter& router, core::DebugSession& session)
    : router_{router}, session_{session}
{
}

void ConsoleFrontend::run()
{
    std::string line;
    while(active_)
    {
        print_prompt();
        if(!std::getline(std::cin, line))
        {
            break;
        }
        handle_line(line);
    }
}

void ConsoleFrontend::print_prompt() const
{
    std::cout << "[sentinel] ";
}

void ConsoleFrontend::handle_line(const std::string& line)
{
    active_ = router_.dispatch(session_, line);
}

} // namespace sentinel::app
