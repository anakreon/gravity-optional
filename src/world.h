#pragma once

#define MAX_TRANSITIONS 8

enum RoomId {
    ROOM_NONE,
    ROOM_ONE,
    ROOM_TWO,
    ROOM_THREE,
    ROOM_FOUR,
    ROOM_COUNT
};

static bool TRUE = true;

struct RoomTransition {
    RoomId to;
    const char* name;
    bool* enabled = &TRUE;
};

struct Room {
    const char* name;
    const char* description;
    struct RoomTransition transitions[MAX_TRANSITIONS];
};

void world_init();

struct Room* world_get_room(RoomId id);