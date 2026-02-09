#include "sentinel/application.hpp"
#include "sentinel/logger.hpp"

namespace sentinel {

Application::Application() {
    sentinel::Logger::get_core_logger()->info(
        "Sentinel Debugger initialized\n");
}

Application::~Application() = default;

void Application::run() {
    sentinel::Logger::get_core_logger()->info("Sentinel Debugger running...\n");
    sentinel::Logger::get_core_logger()->trace(
        "Sentinel Debugger running...\n");
    sentinel::Logger::get_core_logger()->warn("Sentinel Debugger running...\n");
    sentinel::Logger::get_core_logger()->error(
        "Sentinel Debugger running...\n");

    // Main application logic will go here
    while (true) {}
}

} // namespace sentinel
