#pragma once

#include "Command.h"
#include "../utils/String.h"

class AddTeacherCommand: public Command {
    String firstName;
    String familyName;
    String password;

    public:
        AddTeacherCommand(const String& firstName, const String& familyName, const String& password);

        void execute(System& system) override;
};