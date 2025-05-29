#include "AddTeacherCommand.h"

#include <stdexcept>

#include "../models/Admin.h"
#include "../models/User.h"

AddTeacherCommand::AddTeacherCommand(const String& firstName, const String& familyName, const String& password)
  : Command(),
    firstName(firstName),
    familyName(familyName),
    password(password) {}

void AddTeacherCommand::execute(System& system) {
    User* currUser = system.getCurrentUser();

    if (!currUser) {
        throw std::logic_error("Command forbidden!");
    }

    if (Admin* admin = dynamic_cast<Admin*>(currUser)) {
        admin->addNewProfile(firstName, familyName, password, "Teacher");
    } else {
        std::cout << "Command forbidden!\n";
    }
}