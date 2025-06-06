/*
    Name: Miroslav Balev
    №: 9MI0600470
*/

#include "CommandFactory.h"

#include "sstream"
#include "../utils/String.h"
#include "LoginCommand.h"
#include "LogoutCommand.h"
#include "AddTeacherCommand.h"
#include "AddStudentCommand.h"
#include "ChangePasswordCommand.h"
#include "CreateCourseCommand.h"
#include "AddToCourseCommand.h"
#include "AssignHomeworkCommand.h"
#include "MailboxCommand.h"
#include "MessageStudentsCommand.h"
#include "MessageCommand.h"
#include "EnrollCommand.h"
#include "SubmitAssignmentCommand.h"
#include "ClearMailboxCommand.h"
#include "MessageAllCommand.h"
#include "ViewAssignmentSubmissions.h"
#include "GradeAssignmentCommand.h"
#include "GradesCommand.h"

Command* CommandFactory::create(const String& input) {
    std::stringstream ss(input.getElements());
    String cmd;
    ss >> cmd;

    if (cmd == "login") {
        unsigned int id;
        String password;

        ss >> id;
        ss >> password;

        return new LoginCommand(id, password);
    } else if (cmd == "logout") {
        return new LogoutCommand();
    } else if (cmd == "add_teacher") {
        String firstName, familyName, password;
        ss >> firstName >> familyName >> password;

        return new AddTeacherCommand(firstName, familyName, password);
    } else if (cmd == "add_student") {
        String firstName, familyName, password;
        ss >> firstName >> familyName >> password;

        return new AddStudentCommand(firstName, familyName, password);
    } else if (cmd == "change_password") {
        String oldPassword, newPassword;
        ss >> oldPassword >> newPassword;

        return new ChangePasswordCommand(oldPassword, newPassword);
    } else if (cmd == "create_course") {
        String courseName, coursePassword;
        ss >> courseName >> coursePassword;

        return new CreateCourseCommand(courseName, coursePassword);
    } else if (cmd == "add_to_course") {
        String courseName;
        unsigned int studentId;
        ss >> courseName >> studentId;

        return new AddToCourseCommand(courseName, studentId);
    } else if (cmd == "assign_homework") {
        String courseName, homeworkName;
        ss >> courseName >> homeworkName;

        return new AssignHomeworkCommand(courseName, homeworkName);
    } else if (cmd == "mailbox") {
        return new MailboxCommand();
    } else if (cmd == "message_students") {
        String courseName, message;
        ss >> courseName;
        ss >> std::ws;
        getline(ss, message);

        return new MessageStudentsCommand(courseName, message);
    } else if (cmd == "message") {
        String message;
        unsigned int userId;
        ss >> userId;
        ss >> std::ws;
        getline(ss, message);

        return new MessageCommand(userId, message);
    } else if (cmd == "enroll") {
        String courseName, coursePassword;
        ss >> courseName >> coursePassword;

        return new EnrollCommand(courseName, coursePassword);
    } else if (cmd == "submit_assignment") {
        String courseName, assignmentName, submission;
        ss >> courseName >> assignmentName;
        ss >> std::ws;
        getline(ss, submission);

        return new SubmitAssignmentCommand(courseName, assignmentName, submission);
    } else if (cmd == "clear_mailbox") {
        return new ClearMailboxCommand();
    } else if (cmd == "message_all") {
        String message;
        ss >> std::ws;
        getline(ss, message);

        return new MessageAllCommand(message);
    } else if (cmd == "view_assignment_submissions") {
        String courseName, assignmentName;
        ss >> courseName >> assignmentName;

        return new ViewAssignmentSubmissions(courseName, assignmentName);
    } else if (cmd == "grade_assignment") {
        String courseName, assignmentName, message;
        unsigned int studentId;
        double grade;

        ss >> courseName >> assignmentName;
        ss >> studentId;
        ss >> grade;
        ss >> std::ws;
        getline(ss, message);

        return new GradeAssignmentCommand(courseName, assignmentName, studentId, grade, message);
    } else if (cmd == "grades") {
        return new GradesCommand();
    }

    return nullptr;
}
