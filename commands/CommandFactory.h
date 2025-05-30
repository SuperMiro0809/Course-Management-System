/*
    Name: Miroslav Balev
    №: 9MI0600470
*/

#pragma once

#include "../commands//Command.h"
#include "../utils/String.h"

class CommandFactory {
    public:
        static Command* create(const String& input);
};