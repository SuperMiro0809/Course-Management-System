/*
    Name: Miroslav Balev
    №: 9MI0600470
*/

#pragma once

#include "Database.h"
#include "../utils/SubmissionsContainer.h"

class AssigmentSubmissionsDatabase: public Database {
    public:
        explicit AssigmentSubmissionsDatabase(const char* dbName);

        void addNewSubmission(unsigned int assignmentId, unsigned int userId, const String& submission) const;

        bool isAlreadySubmitted(unsigned int assignmentId, unsigned int userId) const;

        SubmissionsContainer getAssignmentSubmissions(unsigned int assignmentId) const;
};