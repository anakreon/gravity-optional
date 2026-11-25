#include <string.h>
#include "parser.h"

Command parse_command(char *input) {

    if(strcmp(input, "look") == 0) return Command::Look;
    if(strcmp(input, "quit") == 0) return Command::Quit;
    if(strcmp(input, "inventory") == 0) return Command::Inventory;

    return Command::Unknown;
}
