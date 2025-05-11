#include "User.h"

User::User() {
  firstName = String();
  familyName = String();
  id = -1;
}

User::User(const char* firstName, const char* familyName, unsigned int id) {
	this->firstName = String(std::strlen(firstName), firstName);
	this->familyName = String(std::strlen(familyName), familyName);
    this->id = id;
}

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
