@echo off

echo Building wengine
echo ================

if not exist "bin\" mkdir bin\

pushd engine
call build.bat
popd

if %ERRORLEVEL% NEQ 0 (echo [ERROR] %ERRORLEVEL% && exit)

pushd testbed
call build.bat
popd

if %ERRORLEVEL% NEQ 0 (echo [ERROR] %ERRORLEVEL% && exit)

echo ================
echo Built wengine without any errors.
