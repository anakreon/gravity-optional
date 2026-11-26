#pragma once

#include "command.h"

enum CommandExecResult {
    EXIT,
    UNKNOWN_COMMAND,
    RUN
};

CommandExecResult actions_execute_command(Command command);