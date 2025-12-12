#include "sentinel_dbg/app/app_context.hpp"

#include "sentinel_dbg/core/debug_session.hpp"
#include "sentinel_dbg/core/target.hpp"

namespace sentinel::app {

AppContext::AppContext(AppConfig cfg) : config_{std::move(cfg)} {}

std::unique_ptr<core::Target> AppContext::make_target() const {
  return std::make_unique<core::Target>(config_.default_target);
}

std::unique_ptr<core::DebugSession> AppContext::make_session() const {
  return std::make_unique<core::DebugSession>(make_target());
}

} // namespace sentinel::app
