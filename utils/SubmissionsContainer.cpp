#include "SubmissionsContainer.h"

#include <fstream>
#include <sstream>

void SubmissionsContainer::freeDynamic() {
    delete[] submissions;
}

void SubmissionsContainer::copyDynamic(const SubmissionsContainer& other) {
    submissions = new Submission[other.capacity];
    for (size_t i = 0; i < other.size; i++) {
        submissions[i] = other.submissions[i];
    }
}

void SubmissionsContainer::resize(size_t newCapacity) {
    capacity = newCapacity;
    Submission* temp = new Submission[capacity];

    for (size_t i = 0; i < size; i++) {
        temp[i] = submissions[i];
    }

    delete[] submissions;
    submissions = temp;
}

SubmissionsContainer::SubmissionsContainer() {
    size = 0;
    capacity = 8;
    submissions = new Submission[capacity];
}

SubmissionsContainer::SubmissionsContainer(const SubmissionsContainer& other) {
    size = other.size;
    capacity = other.capacity;
    copyDynamic(other);
}

SubmissionsContainer& SubmissionsContainer::operator=(const SubmissionsContainer& other) {
    if (this != &other) {
        freeDynamic();
        size = other.size;
        capacity = other.capacity;
        copyDynamic(other);
    }

    return *this;
}

SubmissionsContainer::~SubmissionsContainer() {
    freeDynamic();
}

void SubmissionsContainer::add(const Submission& submission) {
    if (size >= capacity) {
        resize(capacity * 2);
    }

    submissions[size++] = submission;
}

void SubmissionsContainer::loadFromFile(const char* filename, unsigned int assignmentId) {
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
        String idStr, assignmentIdStr, userIdStr, submissionStr;

        getline(ss, idStr, '|');
        getline(ss, assignmentIdStr, '|');
        getline(ss, userIdStr, '|');
        getline(ss, submissionStr);

        unsigned int currId = std::atoi(idStr.getElements());
        unsigned int currAssignmentId = std::atoi(assignmentIdStr.getElements());
        unsigned int currUserId = std::atoi(userIdStr.getElements());

        if (currAssignmentId == assignmentId) {
            add(Submission(currId, currAssignmentId, currUserId, submissionStr));
        }
    }

    DBFile.close();
}

const Submission& SubmissionsContainer::operator[](size_t index) const {
    if (index >= size) {
        throw std::out_of_range("Invalid user index.");
    }
    return submissions[index];
}

size_t SubmissionsContainer::getSubmissionsCount() const {
    return size;
}

std::ostream& operator<<(std::ostream& os, const SubmissionsContainer& container) {
    size_t count = container.getSubmissionsCount();
    if (count == 0) {
        os << "No submissions to show!" << '\n';
    } else {
        for (size_t i = 0; i < count; i++) {
            os << container.submissions[i] << '\n';
        }
    }

    return os;
}
