@echo off

:start
set "version="
set /p version="Enter your IDE[vs2022]: "
if not defined version (
	set version="vs2022"
)
goto execute

:execute
call vendor\bin\premake\premake5.exe %version%
goto start