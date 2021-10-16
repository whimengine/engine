set echo off

mkdir -p ../bin

assembly="testbed"
compilerFlags="-g -fdeclspec -fPIC -Wall -Werror"
includeFlags="-Isrc -I../engine/src/"
linkerFlags="-L../bin/ -lengine -Wl,-rpath,."
defines="-D_DEBUG -DKIMPORT"

echo Building wengine/$assembly

cFiles=$(find . -type f -name "*.c")

echo   Compiling wengine/$assembly

clang $cFiles $compilerFlags -o ../bin/lib$assembly $defines $includeFlags $linkerFlags