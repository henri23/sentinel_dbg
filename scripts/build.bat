@echo off
setlocal enabledelayedexpansion

if "%BUILD_TYPE%"=="" set BUILD_TYPE=Release
if "%BUILD_DIR%"=="" set BUILD_DIR=build

cmake -S . -B "%BUILD_DIR%" -DCMAKE_BUILD_TYPE=%BUILD_TYPE% -DCMAKE_EXPORT_COMPILE_COMMANDS=ON

set SOURCE_JSON=%BUILD_DIR%\compile_commands.json
if exist "%SOURCE_JSON%" (
    copy /Y "%SOURCE_JSON%" compile_commands.json >NUL
)

cmake --build "%BUILD_DIR%" --config %BUILD_TYPE%

endlocal
