#include "platform/platform.h"

#if WPLATFORM_WINDOWS

#include "core/logger.h"

#include <windows.h>
#include <windowsx.h>

typedef struct internal_state {
    HINSTANCE h_instance;
    HWND hwnd;
} internal_state;

LRESULT CALLBACK win32_process_message(HWND hwnd, u32 msg, WPARAM w_param, LPARAM l_param);

b8 platform_startup(platform_state* plat_state, const char* application_name, i32 x, i32 y, i32 width, i32 height) {
    plat_state->internal_state = malloc(sizeof(internal_state));
    internal_state* state = (internal_state*) plat_state->internal_state;
    state->h_instance = GetModuleHandleA(0);

    HICON icon = LoadIcon(state->h_instance, IDI_APPLICATION);
    WNDCLASSA wc;

    memset(&wc, 0, sizeof(wc));

    wc.style = CS_DBLCLKS;
    wc.lpfnWndProc = win32_process_message;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = state->h_instance;
    wc.hIcon = icon;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = NULL;
    wc.lpszClassName = "wengine_window_class";

    if (!RegisterClassA(&wc)) {
        MessageBoxA(0, "Window Registration Failed!", "Windows Platform", MB_ICONERROR | MB_OK);

        return FALSE;
    }

    u32 client_x = x;
    u32 client_y = y;
    u32 client_width = width;
    u32 client_height = height;

    u32 window_x = client_x;
    u32 window_y = client_y;
    u32 window_width = client_width;
    u32 window_height = client_height;

    u32 window_style = WS_OVERLAPPED | WS_SYSMENU | WS_CAPTION;
    u32 window_ex_style = WS_EX_APPWINDOW;

    window_style |= WS_MAXIMIZEBOX;
    window_style |= WS_MINIMIZEBOX;
    window_style |= WS_THICKFRAME;

    RECT border_rect = {0, 0, 0, 0};

    AdjustWindowRectEx(&border_rect, window_style, 0, window_ex_style);

    window_x += border_rect.left;
    window_y += border_rect.top;
    window_width += border_rect.right - border_rect.left;
    window_height += border_rect.bottom - border_rect.top;

    HWND handle = CreateWindowA(
        window_ex_style,
        "wengine_window_class",
        application_name,
        window_style,
        window_x,
        window_y,
        window_width,
        window_height,
        0,
        0,
        state->h_instance,
        0
    );

    if (handle == 0) {
        MessageBoxA(NULL, "Failed to construct window.", "Windows Platform", MB_ICONERROR | MB_OK);
        WFATAL("Failed to construct window.");

        return FALSE;
    } else {
        state->hwnd = handle;
    }

    b32 should_activate = 1; // TODO: If window doesn't accept input, this should be false
    i32 show_window_command_flags = should_activate ? SW_SHOW : SW_SHOWNOACTIVATE;

    ShowWindow(state->hwnd, show_window_command_flags);

    return TRUE;
}

#endif