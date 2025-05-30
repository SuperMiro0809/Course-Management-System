#include "Submission.h"

#include "../services/UsersDatabase.h"

Submission::Submission():
    id(-1),
    assignmentId(-1),
    studentId(-1),
    submission() {}

Submission::Submission(unsigned int id, unsigned int assignmentId, unsigned int studentId, const String& submission):
    id(id),
    assignmentId(assignmentId),
    studentId(studentId),
    submission(submission) {}

std::ostream& operator<<(std::ostream& os, const Submission& s) {
    UsersDatabase usersDb("../users.txt");
    const User* student = usersDb.getUserById(s.studentId);
    String studentName;

    if (student) {
        studentName = student->getFirstName() + " " + student->getFamilyName();
        delete student;
    }

    os << studentName << ", " << s.studentId << ": " << s.submission;
    return os;
}