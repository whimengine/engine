@echo off
setlocal EnableDelayedExpansion

set assembly=testbed
set compilerFlags=-g
set includeFlags=-Isrc -I../engine/src/
set linkerFlags=-L../bin/ -lengine.lib
set defines=-D_DEBUG -DKIMPORT

echo Building wengine\%assembly%%

set cFiles=

for /R %%f in (*.c) do (
	set cFiles=!cFiles! %%f
)

echo   Compiling files in wengine\%assembly%%
clang %cFiles% %compilerFlags% -o ../bin/%assembly%.exe %defines% %includeFlags% %linkerFlags%