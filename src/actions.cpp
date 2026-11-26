#include "command.h"
#include "state.h"
#include "texts.h"
#include "world.h"
#include <cstring>
#include <stdio.h>

enum CommandExecResult {
    EXIT,
    UNKNOWN_COMMAND,
    RUN
};

static CommandExecResult move(char *target);
static CommandExecResult unlock(char *target); 
static short find_transition(char *target, struct RoomTransition *transition);


CommandExecResult actions_execute_command(Command command) {
    if (command.action == Action::Quit) {
        return CommandExecResult::EXIT;
    }
    if (command.action == Action::Unknown) {
        return CommandExecResult::UNKNOWN_COMMAND;
    }
    if (command.action == Action::Move) {
        return move(command.target);
    }
    if (command.action == Action::Unlock) {
        return unlock(command.target);
    }
    return CommandExecResult::UNKNOWN_COMMAND;
}

static CommandExecResult move(char *target) {
    struct RoomTransition target_transition = {};
    if (find_transition(target, &target_transition) != 0) {
        printf("%s\n", T_CANT_GO_THERE);
        return CommandExecResult::RUN;    
    }
    if (*target_transition.enabled == false) {
        printf("%s\n", T_DOOR_IS_LOCKED);
        return CommandExecResult::RUN;   
    }
    state_get_state()->current_room_id = target_transition.to;

    return CommandExecResult::RUN;
}

static CommandExecResult unlock(char *target) {
    struct RoomTransition target_transition = {};
    if (find_transition(target, &target_transition) != 0) {
        printf("%s\n", T_NOTHING_TO_UNLOCK);
        return CommandExecResult::RUN;    
    }
    if (*target_transition.enabled == true) {
        printf("%s\n", T_DOOR_IS_NOT_LOCKED);
        return CommandExecResult::RUN;   
    }
    *target_transition.enabled = true;
    printf("%s\n", T_DOOR_IS_UNLOCKED);

    return CommandExecResult::RUN;
}

static short find_transition(char *target, struct RoomTransition *transition) {
    struct Room *current_room = world_get_room(state_get_state()->current_room_id);
    for(int i = 0; i < MAX_TRANSITIONS && current_room->transitions[i].to != RoomId::ROOM_NONE; ++i) {
        if (strcmp(current_room->transitions[i].name, target) == 0){
            *transition = current_room->transitions[i];
            return 0;
        }
    }
    return 1;
}