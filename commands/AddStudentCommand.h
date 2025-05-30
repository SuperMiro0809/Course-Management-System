/*
    Name: Miroslav Balev
    №: 9MI0600470
*/

#pragma once

#include "Command.h"
#include "../utils/String.h"

class AddStudentCommand: public Command {
    String firstName;
    String familyName;
    String password;

    public:
        AddStudentCommand(const String& firstName, const String& familyName, const String& password);

        void execute(System& system) override;
};