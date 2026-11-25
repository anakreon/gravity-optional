#pragma once

enum RoomId {
    ROOM_ONE,
    ROOM_TWO,
    ROOM_COUNT
};

struct Room {
    const char* name;
    const char* description;
};

void world_init();

struct Room* world_get_room(RoomId id);