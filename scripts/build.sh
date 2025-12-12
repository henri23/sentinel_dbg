#!/usr/bin/env bash
set -euo pipefail

BUILD_TYPE=${BUILD_TYPE:-Release}
BUILD_DIR=${BUILD_DIR:-build}

cmake -S . -B "${BUILD_DIR}" -DCMAKE_BUILD_TYPE="${BUILD_TYPE}" -DCMAKE_EXPORT_COMPILE_COMMANDS=ON

# Expose compile_commands.json at repo root for tooling (symlink if possible, copy otherwise)
SOURCE_JSON="${BUILD_DIR}/compile_commands.json"
if [ -f "${SOURCE_JSON}" ]; then
    ln -sf "${SOURCE_JSON}" compile_commands.json 2>/dev/null || cp "${SOURCE_JSON}" compile_commands.json
fi

cmake --build "${BUILD_DIR}" --config "${BUILD_TYPE}"
