#include "state.h"
#include "world.h"

struct GameState game_state = {};

void state_init() {
    game_state = {
        .current_room_id = ROOM_ONE,
        .world_state = {
            .heavy_door_unlocked = false
        }
    };
}

struct GameState* state_get_state() {
    return &game_state;
}