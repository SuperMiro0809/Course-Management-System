#pragma once

#include "User.h"
#include "../utils/String.h"
#include "../utils/Mailbox.h"

class Student: public User {
    Mailbox mailbox;
    bool isMailboxLoaded = false;

public:
    Student(const char* firstName, const char* familyName, unsigned int id);

    String getRole() const override;

    const Mailbox& getMailbox() const;

    bool getIsMailboxLoaded() const;

    void loadMailbox();

    void clearMailbox();

    User* clone() const override;
};