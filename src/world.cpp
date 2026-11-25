#include "world.h"
#include "texts.h"

static struct Room rooms[ROOM_COUNT] = {};

void world_init() {
    rooms[ROOM_ONE] = {.name = T_ROOM_X_NAME, .description = T_ROOM_X_DESC};
    rooms[ROOM_TWO] = {.name = T_ROOM_Y_NAME, .description = T_ROOM_Y_DESC};
}

struct Room *world_get_room(RoomId id) { return &rooms[id]; }