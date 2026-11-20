#include "game.h"
#include "parser.h"

#include <iostream>
#include <string>

void run_game() {
    std::string input;

    while (true) {
        std::cout << "What do you do? \n";
        std::cout << "> ";


        if (!std::getline(std::cin, input))
            break;

        Command command = parse_command(input);

        if (command == Command::Quit)
            break;

        // Process command

        // Print result
    }
}
