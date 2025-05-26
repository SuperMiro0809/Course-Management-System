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

    virtual ~User() = default;

	virtual String getRole() const = 0;

    const String& getFirstName() const;

    const String& getFamilyName() const;

    unsigned int getId() const;

    friend std::ostream& operator<<(std::ostream& os, const User& user);
};