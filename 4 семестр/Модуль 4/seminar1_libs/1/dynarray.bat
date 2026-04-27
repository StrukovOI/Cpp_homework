@echo off
gcc -Wall -Wextra -std=c11 main.c dynarray.c -o dynarray.exe
if %errorlevel% equ 0 (
    echo Build OK
    dynarray.exe
) else (
    echo Build FAILED
)