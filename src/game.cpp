#include "game.h"
#include "parser.h"
#include "state.h"
#include "texts.h"
#include "world.h"
#include <stdio.h>
#include <stdlib.h>

#define INPUT_MAX_CHAR 100

void run_game() {
    world_init();
    state_init();

    printf("\n");
    printf("%s\n", T_INTRO);
    while (true) {
        GameState *game_state = state_get_state();
        Room *current_room = world_get_room(game_state->current_room_id);
        printf("\n");
        printf("[%s] ", current_room->name);
        printf("%s\n", current_room->description);
        printf("%s\n", T_PROMPT);
        printf("> ");

        char *line = NULL;
        if (read_line(&line) == -1) {
            free(line);
            break;
        }

        Command command = parse_command(line);

        if (command == Command::Quit) {
            printf("- %s\n", T_EXIT);
            free(line);
            break;
        }

        if (command == Command::Unknown) {
            printf("- %s\n", T_UNKNOWN_COMMAND);
            continue;
        }

        // Process command

        // Print result
        free(line);
    }
}

static short read_line(char **line) {
    size_t size = 0;
    ssize_t nread = getline(line, &size, stdin);
    if (nread == -1) {
        return -1;
    }
    // replace the newline by end of string char
    if (nread > 0 && (*line)[nread - 1] == '\n') {
        (*line)[nread - 1] = '\0';
    }
    return 0;
}