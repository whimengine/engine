#pragma once

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef signed char i8;
typedef signed short i16;
typedef signed int i32;
typedef signed long long i64;

typedef float f32;
typedef double f64;

typedef int b32;
typedef char b8;

/* Properly defines static_assert */
#if defined(__clang__) || defined(__gcc__)
#define STATIC_ASSERT _Static_assert
#else
#define STATIC_ASSERT static_assert
#endif

/* Ensures all types are the correct size of bytes */
STATIC_ASSERT(sizeof(u8) == 1, "[ERROR] Expected u8 to be 1 byte.");
STATIC_ASSERT(sizeof(u16) == 2, "[ERROR] Expected u16 to be 2 bytes.");
STATIC_ASSERT(sizeof(u32) == 4, "[ERROR] Expected u32 to be 4 bytes.");
STATIC_ASSERT(sizeof(u64) == 8, "[ERROR] Expected u64 to be 8 bytes.");

STATIC_ASSERT(sizeof(i8) == 1, "[ERROR] Expected i8 to be 1 byte.");
STATIC_ASSERT(sizeof(i16) == 2, "[ERROR] Expected i16 to be 2 bytes.");
STATIC_ASSERT(sizeof(i32) == 4, "[ERROR] Expected i32 to be 4 bytes.");
STATIC_ASSERT(sizeof(i64) == 8, "[ERROR] Expected i64 to be 8 bytes.");

STATIC_ASSERT(sizeof(f32) == 4, "[ERROR] Expected f32 to be 4 byte.");
STATIC_ASSERT(sizeof(f64) == 8, "[ERROR] Expected f64 to be 8 bytes.");

/* Readability */
#define TRUE 1
#define FALSE 0

/* Platform Detection */
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) 
#define KPLATFORM_WINDOWS 1
#ifndef _WIN64
#error "[PLATFORM] wengine does not support Windows 32."
#endif
#elif defined(__linux__) || defined(__gnu_linux__)
#define KPLATFORM_LINUX 1
#if defined(__ANDROID__)
#define KPLATFORM_ANDROID 1
#endif
#elif defined(__unix__)
#define KPLATFORM_UNIX 1
#elif defined(_POSIX_VERSION)
#define KPLATFORM_POSIX 1
#elif __APPLE__
#define KPLATFORM_APPLE 1
#include <TargetConditionals.h>
#if TARGET_IPHONE_SIMULATOR
#define KPLATFORM_IOS 1
#define KPLATFORM_IOS_SIMULATOR 1
#elif TARGET_OS_IPHONE
#define KPLATFORM_IOS 1
#elif TARGET_OS_MAC
#else
#error "[PLATFORM] Unable to recognize Apple Platform."
#endif
#else
#error "[PLATFORM] Unable to recognize Platform."
#endif

#ifdef KEXPORT
#ifdef _MSC_VER
#define KAPI __declspec(dllexport)
#else
#define KAPI __attribute__((visibility("default")))
#endif
#else
#ifdef _MSC_VER
#define KAPI __declspec(dllimport)
#else
#define KAPI
#endif
#endif