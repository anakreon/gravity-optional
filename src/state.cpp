#include "state.h"
#include "world.h"

struct GameState game_state = {
    .current_room_id = ROOM_ONE
};

void state_init() {
    game_state = {
        .current_room_id = ROOM_ONE
    };
}

struct GameState* state_get_state() {
    return &game_state;
}