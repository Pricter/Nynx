#pragma once

#include "defines.h"

struct game;

typedef struct application_config {
    i16 start_pos_x;
    i16 start_pos_y;
    i16 start_width;
    i16 start_height;
    char* name;
} application_config;

NAPI b8 application_create(struct game* game_inst);
NAPI b8 application_run();
