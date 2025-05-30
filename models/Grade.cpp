#include "Grade.h"

#include "../services/CourseAssignmentsDatabase.h"
#include "../services/CoursesDatabase.h"

Grade::Grade(): id(-1), assignmentId(-1), studentId(-1), grade(0), message() {}

Grade::Grade(
    unsigned int id,
    unsigned int assignmentId,
    unsigned int studentId,
    double grade,
    String message
): id(id), assignmentId(assignmentId), studentId(studentId), grade(grade), message(message) {}

std::ostream& operator<<(std::ostream& os, const Grade& grade) {
    CourseAssignmentsDatabase courseAssignmentsDb("../course_assignments.txt");
    const CourseAssignment* courseAssignment = courseAssignmentsDb.findCourseAssigment(grade.assignmentId);

    if (!courseAssignment) return os;

    CoursesDatabase coursesDb("../courses.txt");
    const Course* course = coursesDb.findCourseById(courseAssignment->getCourseId());

    if (!course) {
        delete courseAssignment;
        return os;
    }

    os << course->getCourseName() << " | "
       << courseAssignment->getAssignmentName() << " | "
       << grade.grade << " | "
       << grade.message;

    delete courseAssignment;
    delete course;

    return os;
}
