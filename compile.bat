@echo off

if exist build rmdir /s /q build
mkdir build

g++ -o .\build\game.exe .\src\*.cpp -Wall -Wextra

pause