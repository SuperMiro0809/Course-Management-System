/*
	Name: Miroslav Balev
	№: 9MI0600470
*/

#include "User.h"

User::User() {
  firstName = String();
  familyName = String();
  id = -1;
}

User::User(const char* firstName, const char* familyName, unsigned int id):
    firstName(firstName),
    familyName(familyName),
    id(id) { }

User::User(const String& firstName, const String& familyName, unsigned int id):
	firstName(firstName),
	familyName(familyName),
	id(id) {}

const String& User::getFirstName() const {
	return firstName;
}

const String& User::getFamilyName() const {
	return familyName;
}

unsigned int User::getId() const {
	return id;
}

std::ostream& operator<<(std::ostream& os, const User& user) {
	os << user.getFirstName() << " " << user.getFamilyName() << " | " << user.getId();
	return os;
}
