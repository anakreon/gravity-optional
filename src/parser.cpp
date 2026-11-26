#include "parser.h"
#include <stdbool.h>
#include <string.h>

#define MAX_INPUT_LENGTH 256

static short read_string(char *input, int start_index, int *end_index, char *string, bool allow_space);
static Action map_action(char *action);

Command unknown_command = {
    .action = Action::Unknown,
    .target = ""
};

struct Command parse_command(char *input) {
    int char_index = 0;

    char action[MAX_INPUT_LENGTH];
    if (read_string(input, char_index, &char_index, action, false) != 0) {
        return unknown_command;
    }
    while (input[char_index] == ' ') {
        char_index++;
    }

    char target[TARGET_MAX_LENGTH];
    if (input[char_index] != '\n' && input[char_index] != '\0') {
        if (read_string(input, char_index, &char_index, target, true) != 0) {
            return unknown_command;
        }
    }

    struct Command command = {};
    command.action = map_action(action);
    strcpy(command.target, target);

    return command;
}

static short read_string(char *input, int start_index, int *end_index, char *string, bool allow_space) {
    int i = 0;
    while ((allow_space || input[start_index + i] != ' ') && input[start_index + i] != '\n' && input[start_index + i] != '\0') {
        string[i] = input[start_index + i];
        i++;
    }
    if (i <= 0) {
        return 1;
    }
    string[i] = '\0';
    *end_index = start_index + i;
    return 0;
}

static Action map_action(char *action) {
    if (strcmp(action, "look") == 0)
        return Action::Look;
    if (strcmp(action, "quit") == 0)
        return Action::Quit;
    if (strcmp(action, "inventory") == 0)
        return Action::Inventory;
    if (strcmp(action, "move") == 0)
        return Action::Move;
    if (strcmp(action, "unlock") == 0)
        return Action::Unlock;

    return Action::Unknown;
}
