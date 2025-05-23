#pragma once

#include "defines.h"

typedef struct event_context {
    union {
        i64 i64[2];
        u64 u64[2];
        f64 f64[2];

        i32 i32[4];
        u32 u32[4];
        f32 f32[4];
        
        i16 i16[8];
        u16 u16[8];
        
        i8 i8[16];
        u8 u8[16];

        char c[32];
    } data;
} event_context;

b8 event_initialize();
void event_shutdown();

typedef b8 (*PFN_on_event)(u16 code, void* sender, void* listener_inst, event_context data);

NAPI b8 event_register(u16 code, void* listener, PFN_on_event on_event);
NAPI b8 event_unregister(u16 code, void* listener, PFN_on_event on_event);
NAPI b8 event_fire(u16 code, void* sender, event_context context);

typedef enum system_event_code {
    EVENT_CODE_APPLICATION_QUIT = 0x01,
    EVENT_CODE_KEY_PRESSED = 0x02,
    EVENT_CODE_KEY_RELEASED = 0x03,
    EVENT_CODE_BUTTON_PRESSED = 0x04,
    EVENT_CODE_BUTTON_RELEASED = 0x05,
    EVENT_CODE_MOUSE_MOVED = 0x06,
    EVENT_CODE_MOUSE_WHEEL = 0x07,
    EVENT_CODE_RESIZED = 0x08,
    MAX_EVENT_CODE = 0xFF,
} system_event_code;