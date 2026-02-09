cmake_minimum_required(VERSION 3.20)

project(sentinel_dbg VERSION 0.1.0 LANGUAGES CXX)

option(SENTINEL_DBG_BUILD_TESTS "Build unit tests" OFF)
option(SENTINEL_DBG_WARNINGS_AS_ERRORS "Treat warnings as errors" ON)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

include(CompilerWarnings)

# Third-party dependencies
add_subdirectory(third_party/spdlog)

add_library(sentinel_dbg_core)
target_sources(sentinel_dbg_core PRIVATE src/application.cpp src/logger.cpp)
target_include_directories(
    sentinel_dbg_core
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)
target_compile_features(sentinel_dbg_core PUBLIC cxx_std_23)
target_link_libraries(sentinel_dbg_core PUBLIC spdlog::spdlog)
set_project_warnings(sentinel_dbg_core)

add_executable(sentinel_dbg apps/console/main.cpp)
target_link_libraries(sentinel_dbg PRIVATE sentinel_dbg_core)
set_target_properties(sentinel_dbg PROPERTIES OUTPUT_NAME "sentinel-dbg")

if(SENTINEL_DBG_BUILD_TESTS)
    enable_testing()
    # add_subdirectory(tests)
endif()
