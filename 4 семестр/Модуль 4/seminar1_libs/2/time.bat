@echo off
g++ -Wall -Wextra -std=c++17 main.cpp time.cpp -o time.exe
if %errorlevel% equ 0 (
    echo Build OK
    time.exe
) else (
    echo Build FAILED
)