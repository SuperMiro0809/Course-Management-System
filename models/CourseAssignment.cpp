/*
    Name: Miroslav Balev
    №: 9MI0600470
*/

#include "CourseAssignment.h"

CourseAssignment::CourseAssignment(unsigned int id, unsigned int courseId, const String& assignmentName):
    id(id),
    courseId(courseId),
    assignmentName(assignmentName) {}

unsigned int CourseAssignment::getCourseId() const {
    return courseId;
}

const String& CourseAssignment::getAssignmentName() const {
    return assignmentName;
}