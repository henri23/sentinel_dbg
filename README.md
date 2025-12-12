# Sentinel Debugger (scaffold)

A small, multi-platform C++20 starter for a debugger-style application. The layout is kept lean but ready for growth: a core library, a console frontend, and room for platform-specific backends or UI layers.

## Requirements
- CMake ≥ 3.20
- A C++20 compiler (MSVC 19.3x, Clang 12+, or GCC 10+ recommended)

## Building
Use the helper scripts to configure and build in `./build` (defaults to Release):

```bash
scripts/build.sh            # Linux/macOS
scripts/build.bat           # Windows (Developer Prompt)
```
These scripts also export `compile_commands.json` to the repo root for language tooling.

You can still use CMake directly:
```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build
```

## Project structure
- `CMakeLists.txt` — root build; targets `sentinel_dbg_core` (library) and `sentinel_dbg` (console app).
- `cmake/` — shared CMake helpers (warnings, policy toggles).
- `include/sentinel_dbg/` — public headers for the core library and app utilities.
- `src/` — core and app implementations.
- `apps/console/` — CLI frontend wiring commands to the core.
- `scripts/` — cross-platform build entrypoints.

## Next steps (suggested)
- Flesh out platform adapters under `src/core/` (e.g., symbol resolution, memory access).
- Add a `tests/` directory with `CTest` or Catch2/GoogleTest.
- Introduce logging/tracing and richer command handling (history, scripting).

## License
GPL-3.0-only. See `LICENSE`.
