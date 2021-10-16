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

#define WASSERT_MSG(expr, message) {                                  \
    if (expr) {} else {                                               \
        report_assertion_failure(#expr, message, __FILE__, __LINE__); \
        debugBreak();                                                 \
    }                                                                 \
}

#ifdef _DEBUG
#define WASSERT_DEBUG(expr) {                                    \
    if (expr) {} else {                                          \
        report_assertion_failure(#expr, "", __FILE__, __LINE__); \
        debugBreak();                                            \
    }                                                            \
}

#else
#define WASSERT_DEBUG(expr)
#endif
#else
#define WASSERT(expr)
#define WASSERT_MSG(expr)
#define WASSERT_DEBUG(expr)
#endif