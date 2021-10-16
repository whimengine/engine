#pragma once

#include "defines.h"

/* Comment out to disable assertions */
#define WASSERTIONS_ENABLED

#ifdef WASSERTIONS_ENABLED
#if _MSC_VER
#include <intrin.h>
#define debugBreak() __debugBreak()
#else
#define debugBreak() __builting_trap()
#endif

void report_assertion_failure(const char* expression, const char* message, const char* file, i32 line);

#define WASSERT(expr) {                                          \
    if (expr) {} else {                                          \
        report_assertion_failure(#expr, "", __FILE__, __LINE__); \
        debugBreak();                                            \
    }                                                            \
}

#endif