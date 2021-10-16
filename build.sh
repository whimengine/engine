set echo on

if [[ -z "${VULKAN_SDK}" ]]; then
    source vulkan/setup-env.sh
fi

echo Building wengine/**
echo ====================

pushd engine
source build.sh
popd

ERRORLEVEL=$?
if [[ $ERRORLEVEL -ne 0 ]]; then
    echo [ERROR] $ERRORLEVEL && exit
fi

pushd testbed
source build.sh
popd

ERRORLEVEL=$?
if [[ $ERRORLEVEL -ne 0 ]]; then
    echo [ERROR] $ERRORLEVEL && exit
fi

echo ====================
echo Built wengine