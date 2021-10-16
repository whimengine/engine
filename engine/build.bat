@echo off
setlocal EnableDelayedExpansion

set assembly=engine
set compilerFlags=-g -shared -Wvarargs -Wall -Werror
set includeFlags=-Isrc -I%VULKAN_SDK%/Include
set linkerFlags=-luser32 -lvulkan-1 -L%VULKAN_SDK%/Lib
set defines=-D_DEBUG -DWEXPORT -D_CRT_SECURE_NO_WARNINGS

echo Building wengine\%assembly%%

set cFiles=

for /R %%f in (*.c) do (
	set cFiles=!cFiles! %%f
)
echo   Compiling wengine\%assembly%%
clang %cFiles% %compilerFlags% -o ../bin/%assembly%.dll %defines% %includeFlags% %linkerFlags%