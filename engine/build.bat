@echo off
setlocal EnableDelayedExpansion

echo Building wengine\engine

set cFiles=

for /R %%f in (*.c) do (
	set cFiles=!cFiles! %%f
)

echo   Found files "%cFiles%" in wengine\engine

set assembly=engine
set compilerFlags=-g -shared -Wvarargs -Wall -Werror
set includeFlags=-Isrc -I%VULKAN_SDK%/Include
set linkerFlags=-luser32 -lvulkan-1 -L%VULKAN_SDK%/Lib
set defines=-D_DEBUG -DKEXPORT -D_CRT_SECURE_NO_WARNINGS

echo     Compiling files in wengine\%assembly%%
clang %cFiles% %compilerFlags% -o ../bin/%assembly%.dll %defines% %includeFlags% %linkerFlags%