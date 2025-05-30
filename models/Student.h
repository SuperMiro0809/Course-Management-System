#pragma once

#include "User.h"
#include "../utils/String.h"
#include "../utils/Mailbox.h"
#include "../utils/GradesContainer.h"

class Student: public User {
    Mailbox mailbox;
    bool isMailboxLoaded = false;

    GradesContainer grades;
    bool areGradesLoaded = false;
public:
    Student(const char* firstName, const char* familyName, unsigned int id);

    Student(const String& firstName, const String& familyName, unsigned int id);

    String getRole() const override;

    const Mailbox& getMailbox() const;

    bool getIsMailboxLoaded() const;

    void loadMailbox();

    void clearMailbox();

    const GradesContainer& getGrades() const;

    bool getAreGradesLoaded() const;

    void loadGrades();

    User* clone() const override;
};