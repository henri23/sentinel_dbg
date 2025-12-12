#include "sentinel_dbg/app/app_context.hpp"
#include "sentinel_dbg/app/console_frontend.hpp"
#include "sentinel_dbg/core/command_router.hpp"
#include "sentinel_dbg/core/debug_session.hpp"

#include <iostream>

namespace {

void register_default_commands(sentinel::core::CommandRouter &router) {
    router.register_command("run", [](sentinel::core::DebugSession &session,
                                      const auto &) { session.run(); });
    router.register_command("step", [](sentinel::core::DebugSession &session,
                                       const auto &) { session.step(); });
    router.register_command("stop", [](sentinel::core::DebugSession &session,
                                       const auto &) { session.stop(); });
    router.register_command(
        "bp", [](sentinel::core::DebugSession &session, const auto &args) {
            if (args.empty()) {
                std::cout << "Breakpoints:\n";
                for (const auto &bp : session.list_breakpoints()) {
                    std::cout << " - " << bp.location
                              << (bp.enabled ? "" : " (disabled)") << "\n";
                }
                return;
            }
            session.add_breakpoint(sentinel::core::Breakpoint{args.front()});
            std::cout << "Added breakpoint at " << args.front() << "\n";
        });
}

} // namespace

int main() {
    sentinel::app::AppContext context{};
    auto session = context.make_session();

    sentinel::core::CommandRouter router;
    register_default_commands(router);

    sentinel::app::ConsoleFrontend console{router, *session};
    console.run();

    return 0;
}
