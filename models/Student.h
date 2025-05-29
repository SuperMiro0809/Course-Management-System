#pragma once

#include "User.h"
#include "../utils/String.h"
#include "../utils/Mailbox.h"

class Student: public User {
    Mailbox mailbox;

public:
    Student(const char* firstName, const char* familyName, unsigned int id);

    String getRole() const override;

    const Mailbox& getMailbox() const;

    void clearMailbox();
};