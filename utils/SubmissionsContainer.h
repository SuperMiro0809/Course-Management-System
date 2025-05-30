#pragma once

#include "../models/Submission.h"

class SubmissionsContainer {
    Submission* submissions;
    size_t size;
    size_t capacity;

    void freeDynamic();

    void copyDynamic(const SubmissionsContainer& other);

    void resize(size_t newCapacity);

    public:
        SubmissionsContainer();

        SubmissionsContainer(const SubmissionsContainer& other);

        SubmissionsContainer& operator=(const SubmissionsContainer& other);

        ~SubmissionsContainer();

        void add(const Submission& submission);

        void loadFromFile(const char* filename, unsigned int assignmentId);

        const Submission& operator[](size_t index) const;

        size_t getSubmissionsCount() const;

        friend std::ostream& operator<<(std::ostream& os, const SubmissionsContainer& container);
};