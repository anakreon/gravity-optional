#include "parser.h"

Command parse_command(const std::string& input) {
    if (input == "look") return Command::Look;
    if (input == "quit") return Command::Quit;
    if (input == "inventory") return Command::Inventory;

    return Command::Unknown;
}
