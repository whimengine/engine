#pragma once

#include "defines.h"

typedef struct platform_state {
    void* internal_state;
} platform_state;

WAPI b8 platform_startup(platform_state* plat_state, const char* application_name, i32 x, i32 y, i32 width, i32 height);

WAPI void platform_shutdown(platform_state* plat_state);

WAPI b8 platform_pump_messages(platform_state* plat_state);

void* platform_allocate(u64 size, b8 aligned);
void platform_free(void* block, b8 aligned);
void* platform_zero_memory(void* block, u64 size);
void* platform_copy_memory(void* dest, const void* source, u64 size);
void* platform_set_memory(void* dest, i32 value, u64 size);

void platform_console_write(const char* message, u8 color);
void platform_console_write_error(const char* message, u8 color);

f64 platform_get_absolute_time();

/**
 * Sleep on the thread for provided ms. This blocks the main thread.
 * Should only be used for giving time back to the OS for unused update power.
 */
void platform_sleep(u64 ms);