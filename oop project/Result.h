#ifndef RESULT_H
#define RESULT_H

#include "Student.h"
#include "Subject.h"
#include <vector>
using namespace std;

class Result {
private:
    Student student;
    vector<Subject> subjects;
    double gpa;
    bool isPassed;

    // Calculate GPA from all subjects
    void calculateGPA();

    // Determine pass/fail status
    void determineStatus();

public:
    // Constructors
    Result();
    Result(Student student);

    // Add subject to the result
    void addSubject(Subject subject);

    // Getters
    Student getStudent() const;
    vector<Subject> getSubjects() const;
    double getGPA() const;
    bool getPassStatus() const;

    // Generate and display formatted result card
    void generateResultCard() const;

    // Operator overloading - compare students by GPA
    bool operator>(const Result& other) const;
    bool operator<(const Result& other) const;
    bool operator==(const Result& other) const;
};

#endif
