/*
    Name: Miroslav Balev
    №: 9MI0600470
*/

#pragma once

#include "User.h"
#include "../utils/Mailbox.h"
#include "../utils/String.h"

class Teacher: public User {
    Mailbox mailbox;
    bool isMailboxLoaded = false;
public:
    Teacher(const char* firstName, const char* familyName, unsigned int id);

    Teacher(const String& firstName, const String& familyName, unsigned int id);

    String getRole() const override;

    const Mailbox& getMailbox() const;

    bool getIsMailboxLoaded() const;

    void loadMailbox();

    void clearMailbox();

    User* clone() const override;
};