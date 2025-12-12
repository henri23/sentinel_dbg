#pragma once

#include <functional>
#include <string>
#include <unordered_map>
#include <vector>

namespace sentinel::core {

class DebugSession;

class CommandRouter {
  public:
    using CommandHandler = std::function<void(DebugSession &, const std::vector<std::string> &)>;

    void register_command(std::string name, CommandHandler handler);
    bool dispatch(DebugSession &session, const std::string &line) const;

  private:
    std::unordered_map<std::string, CommandHandler> handlers_;
};

} // namespace sentinel::core
