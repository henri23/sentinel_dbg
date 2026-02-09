#pragma once

#include <spdlog/spdlog.h>

namespace sentinel {

class Logger {
public:
    static void init();

    static std::shared_ptr<spdlog::logger>& get_core_logger() {
        return core_logger_;
    }

    static std::shared_ptr<spdlog::logger>& get_debug_logger() {
        return debugger_logger_;
    }

private:
    static inline std::shared_ptr<spdlog::logger> core_logger_;
    static inline std::shared_ptr<spdlog::logger> debugger_logger_;
};

} // namespace sentinel
