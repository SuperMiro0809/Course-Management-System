#pragma once

#include "Database.h"

class AssigmentSubmissionsDatabase: public Database {
    public:
        explicit AssigmentSubmissionsDatabase(const char* dbName);

        void addNewSubmission(unsigned int assignmentId, unsigned int userId, const String& submission) const;

        bool isAlreadySubmitted(unsigned int assignmentId, unsigned int userId) const;
};