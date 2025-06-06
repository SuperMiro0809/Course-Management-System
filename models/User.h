/*
	Name: Miroslav Balev
	№: 9MI0600470
*/

#pragma once

#include "../utils/String.h"

class User {
protected:
	String firstName;
    String familyName;
    unsigned int id;

public:
	User();

    User(const char* firstName, const char* familyName, unsigned int id);

	User(const String& firstName, const String& familyName, unsigned int id);

    virtual ~User() = default;

	virtual String getRole() const = 0;

	virtual User* clone() const = 0;

    const String& getFirstName() const;

    const String& getFamilyName() const;

    unsigned int getId() const;

    friend std::ostream& operator<<(std::ostream& os, const User& user);
};