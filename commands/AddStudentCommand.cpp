#include "AddStudentCommand.h"

#include <stdexcept>
#include "../models/User.h"
#include "../services/UsersDatabase.h"

AddStudentCommand::AddStudentCommand(const String& firstName, const String& familyName, const String& password)
  : Command(),
    firstName(firstName),
    familyName(familyName),
    password(password) {}

void AddStudentCommand::execute(System& system) {
    const User* currUser = system.getCurrentUser();

    if (!currUser) {
        throw std::logic_error("Command forbidden!");
    }

    UsersDatabase usersDb("../users.txt");

    usersDb.addNewUser(firstName, familyName, "Student", password);
}