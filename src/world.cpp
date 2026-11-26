#include "state.h"
#include "world.h"
#include "texts.h"
#include <stdbool.h>

static struct Room rooms[ROOM_COUNT] = {};

void world_init() {
    struct GameState *game_state = state_get_state();

    rooms[ROOM_ONE] = {
        .name = T_ROOM_ONE_NAME,
        .description = T_ROOM_ONE_DESC,
        .transitions = {
            {
                .to = ROOM_TWO,
                .name = "door on the right"
            },
            {
                .to = ROOM_THREE,
                .name = "heavy door",
                .enabled = &game_state->world_state.heavy_door_unlocked
            }
        }
    };
    rooms[ROOM_TWO] = {
        .name = T_ROOM_TWO_NAME,
        .description = T_ROOM_TWO_DESC,
        .transitions = {
            {
                .to = ROOM_ONE,
                .name = "door on the left"
            },
            {
                .to = ROOM_FOUR,
                .name = "slide"
            }
        }
    };
    rooms[ROOM_THREE] = {
        .name = T_ROOM_THREE_NAME,
        .description = T_ROOM_THREE_DESC,
        .transitions = {
            {
                .to = ROOM_ONE,
                .name = "heavy door",
                .enabled = &game_state->world_state.heavy_door_unlocked
            },
            {
                .to = ROOM_FOUR,
                .name = "hidden passage"
            }
        }
    };
    rooms[ROOM_FOUR] = {
        .name = T_ROOM_FOUR_NAME,
        .description = T_ROOM_FOUR_DESC,
        .transitions = {
            {
                .to = ROOM_THREE,
                .name = "hidden passage"
            }
        }
    };
}

struct Room *world_get_room(RoomId id) { return &rooms[id]; }