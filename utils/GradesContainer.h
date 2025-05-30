#pragma once

#include "../models/Grade.h"

class GradesContainer {
    Grade* grades;
    size_t size;
    size_t capacity;

    void freeDynamic();

    void copyDynamic(const GradesContainer& other);

    void resize(size_t newCapacity);

    public:
        GradesContainer();

        GradesContainer(const GradesContainer& other);

        GradesContainer& operator=(const GradesContainer& other);

        ~GradesContainer();

        void add(const Grade& grade);

        const Grade& operator[](size_t index) const;

        void loadFromFile(const char* filename, unsigned int studentId);

        size_t getGradesCount() const;

        friend std::ostream& operator<<(std::ostream& os, const GradesContainer& container);
};