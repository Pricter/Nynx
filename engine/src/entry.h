#pragma once

#include "core/application.h"
#include "core/logger.h"
#include "game_types.h"
#include "core/nmemory.h"

extern b8 create_game(game* out_game);

int main(void) {
    initialize_memory();

    game game_inst;
    if(!create_game(&game_inst)) {
        NFATAL("Could not create game");
        return -1;
    }

    if(!game_inst.render || !game_inst.update || !game_inst.initialize || !game_inst.on_resize) {
        NFATAL("The game's function pointers are not set");
        return -1;
    }

    if(!application_create(&game_inst)) {
        NINFO("Application failed to create");
        return 1;
    }

    if(!application_run()) {
        NINFO("Application did not shutdown gracefully");
        return 2;
    }

    shutdown_memory();
    return 0;
}