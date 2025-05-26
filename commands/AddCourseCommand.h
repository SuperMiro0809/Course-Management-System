#pragma once

#include "Command.h"
#include "../utils/String.h"

class AddCourseCommand: public Command {
    String courseName;
    String coursePassword;
    String password;

    public:
        AddCourseCommand(const String& courseName, const String& coursePassword);

        void execute(System& system) override;
};