@echo off

if exist build rmdir /s /q build
mkdir build

XCOPY .\third_party\SDL3\bin\SDL3.dll .\build\ /E /I /Y

g++ -o .\build\game.exe -I.\include\ -I.\third_party\SDL3\include\ -L.\third_party\SDL3\lib\ .\src\*.cpp -lSDL3 -Wall -Wextra

pause