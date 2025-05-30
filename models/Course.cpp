#include "Course.h"

Course::Course(unsigned int id, const String& courseName, const String& coursePassword, unsigned int creatorId):
    id(id),
    courseName(courseName),
    coursePassword(coursePassword),
    creatorId(creatorId) {}

unsigned int Course::getId() const {
    return id;
}

const String& Course::getPassword() const {
    return coursePassword;
}

unsigned int Course::getCreatorId() const {
    return creatorId;
}

const String& Course::getCourseName() const {
    return courseName;
}