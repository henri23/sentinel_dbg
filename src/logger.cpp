#include "sentinel/logger.hpp"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace sentinel {

void Logger::init() {
    spdlog::set_pattern("%^[%T] %n: %v%$");

    core_logger_ = spdlog::stdout_color_mt("CORE");
    core_logger_->set_level(spdlog::level::trace);

    debugger_logger_ = spdlog::stdout_color_mt("DEBUGGER");
    debugger_logger_->set_level(spdlog::level::trace);
}

} // namespace sentinel
