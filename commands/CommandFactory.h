#pragma once

#include "../commands//Command.h"
#include "../utils/String.h"

class CommandFactory {
    public:
        Command* create(const String& input);
};