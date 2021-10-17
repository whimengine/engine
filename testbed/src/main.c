#include <core/logger.h>
#include <core/asserts.h>

#include <platform/platform.h>

int main(void) {
    WFATAL("A fatal message: %f", 3.14f);
    WERROR("An error message: %f", 3.14f);
    WWARN("A warn message: %f", 3.14f);
    WINFO("An info message: %f", 3.14f);
    WDEBUG("A debug message: %f", 3.14f);
    WTRACE("A trace message: %f", 3.14f);

    platform_state state;

    if (platform_startup(&state, "WEngine Testbed", 100, 100, 1280, 720)) {
        while (TRUE) {
            platform_pump_messages(&state);
        }
    }

    platform_shutdown(&state);

    return 0;
}