/*
    Name: Miroslav Balev
    №: 9MI0600470
*/

#include "GradesContainer.h"

#include <fstream>
#include <sstream>

void GradesContainer::freeDynamic() {
    delete[] grades;
}

void GradesContainer::copyDynamic(const GradesContainer& other) {
    grades = new Grade[other.capacity];
    for (size_t i = 0; i < other.size; i++) {
        grades[i] = other.grades[i];
    }
}

void GradesContainer::resize(size_t newCapacity) {
    capacity = newCapacity;
    Grade* temp = new Grade[capacity];

    for (size_t i = 0; i < size; i++) {
        temp[i] = grades[i];
    }

    delete[] grades;
    grades = temp;
}

GradesContainer::GradesContainer() {
    size = 0;
    capacity = 8;
    grades = new Grade[capacity];
}

GradesContainer::GradesContainer(const GradesContainer& other) {
    size = other.size;
    capacity = other.capacity;
    copyDynamic(other);
}

GradesContainer& GradesContainer::operator=(const GradesContainer& other) {
    if (this != &other) {
        freeDynamic();
        size = other.size;
        capacity = other.capacity;
        copyDynamic(other);
    }

    return *this;
}

GradesContainer::~GradesContainer() {
    freeDynamic();
}

void GradesContainer::add(const Grade& grade) {
    if (size >= capacity) {
        resize(capacity * 2);
    }

    grades[size++] = grade;
}

const Grade& GradesContainer::operator[](size_t index) const {
    if (index >= size) {
        throw std::out_of_range("Invalid user index.");
    }
    return grades[index];
}

void GradesContainer::loadFromFile(const char* filename, unsigned int studentId) {
    std::ifstream DBFile(filename);

    if (!DBFile.is_open()) {
        throw std::runtime_error("Error: could not open database file");
    }

    String line;
    while (true) {
        getline(DBFile, line);

        if (DBFile.eof()) {
            break;
        }

        std::stringstream ss(line.getElements());
        String idStr, assignmentIdStr, studentIdStr, gradeStr, messageStr;

        getline(ss, idStr, '|');
        getline(ss, assignmentIdStr, '|');
        getline(ss, studentIdStr, '|');
        getline(ss, gradeStr, '|');
        getline(ss, messageStr);

        unsigned int currId = std::atoi(idStr.getElements());
        unsigned int currAssignmentId = std::atoi(assignmentIdStr.getElements());
        unsigned int currStudentId = std::atoi(studentIdStr.getElements());
        double currGrade = std::atof(gradeStr.getElements());

        if (currStudentId == studentId) {
            add(Grade(currId, currAssignmentId, currStudentId, currGrade, messageStr));
        }
    }

    DBFile.close();
}

size_t GradesContainer::getGradesCount() const {
    return size;
}

std::ostream& operator<<(std::ostream& os, const GradesContainer& container) {
    size_t count = container.getGradesCount();
    if (count == 0) {
        os << "No grades to show!" << '\n';
    } else {
        for (size_t i = 0; i < count; i++) {
            os << container.grades[i] << '\n';
        }
    }

    return os;
}