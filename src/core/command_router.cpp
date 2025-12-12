#include "sentinel_dbg/core/command_router.hpp"

#include "sentinel_dbg/core/debug_session.hpp"

#include <iostream>
#include <sstream>

namespace sentinel::core {

void CommandRouter::register_command(std::string name, CommandHandler handler) {
    handlers_.emplace(std::move(name), std::move(handler));
}

bool CommandRouter::dispatch(DebugSession &session,
                             const std::string &line) const {
    std::istringstream stream{line};
    std::string cmd;
    stream >> cmd;

    if (cmd.empty()) {
        return true;
    }

    std::vector<std::string> args;
    for (std::string arg; stream >> arg;) {
        args.push_back(std::move(arg));
    }

    if (cmd == "quit" || cmd == "exit") {
        return false;
    }

    auto it = handlers_.find(cmd);
    if (it == handlers_.end()) {
        std::cerr << "Unknown command: " << cmd << "\n";
        return true;
    }

    it->second(session, args);
    return true;
}

} // namespace sentinel::core
