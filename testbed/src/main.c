#include <core/logger.h>
#include <core/asserts.h>

int main(void) {
    WFATAL("A fatal message: %f", 3.14f);
    WERROR("An error message: %f", 3.14f);
    WWARN("A warn message: %f", 3.14f);
    WINFO("An info message: %f", 3.14f);
    WDEBUG("A debug message: %f", 3.14f);
    WTRACE("A trace message: %f", 3.14f);

    WASSERT(1 == 0);

    return 0;
}