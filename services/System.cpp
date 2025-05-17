#include "System.h"

System::System() = default;

const User* System::getCurrentUser() const {
    return currentUser;
}

void System::setCurrentUser(User* user) {
    currentUser = user;
}

void System::logout() {
    currentUser = nullptr;
}
