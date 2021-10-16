set echo on

mkdir -p ../bin

assembly="engine"
compilerFlags="-g -shared -fdeclspec -fPIC -Wall -Werror"
includeFlags="-Isrc -I$VULKAN_SDK/include"
linkerFlags="-lvulkan -lxcb -lX11 -lX11-xcb -lxkbcommon -L$VULKAN_SDK/lib -L/usr/X11R6/lib"
defines="-D_DEBUG -DWEXPORT"

echo Building wengine/$assembly

cFiles=$(find . -type f -name "*.c")

echo   Compiling wengine/$assembly

clang $cFiles $compilerFlags -o ../bin/lib$assembly.so $defines $includeFlags $linkerFlags