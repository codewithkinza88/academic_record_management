#include "Result.h"
#include <iostream>
#include <iomanip>
using namespace std;

// Default Constructor
Result::Result() {
    gpa = 0.0;
    isPassed = false;
}

// Parameterized Constructor
Result::Result(Student student) {
    this->student = student;
    gpa = 0.0;
    isPassed = false;
}

// Add subject to the result
void Result::addSubject(Subject subject) {
    subjects.push_back(subject);
    calculateGPA();
    determineStatus();
}

// Calculate GPA from all subjects
void Result::calculateGPA() {
    if (subjects.empty()) {
        gpa = 0.0;
        return;
    }

    double totalGradePoints = 0.0;
    for (const auto& subject : subjects) {
        totalGradePoints += subject.getGradePoints();
    }

    gpa = totalGradePoints / subjects.size();
}

// Determine pass/fail status (fail if any subject has grade F)
void Result::determineStatus() {
    isPassed = true;
    for (const auto& subject : subjects) {
        if (subject.calculateGrade() == 'F') {
            isPassed = false;
            break;
        }
    }
}

// Getters
Student Result::getStudent() const {
    return student;
}

vector<Subject> Result::getSubjects() const {
    return subjects;
}

double Result::getGPA() const {
    return gpa;
}

bool Result::getPassStatus() const {
    return isPassed;
}

// Generate and display formatted result card
void Result::generateResultCard() const {
    cout << "\n========================================" << endl;
    cout << "      STUDENT RESULT CARD" << endl;
    cout << "========================================" << endl;
    cout << "Name     :  " << student.getName() << endl;
    cout << "Roll No  :  " << student.getRollNumber() << endl;
    cout << "Semester :  " << student.getSemester();

    // Add ordinal suffix
    int sem = student.getSemester();
    if (sem == 1) cout << "st";
    else if (sem == 2) cout << "nd";
    else if (sem == 3) cout << "rd";
    else cout << "th";
    cout << endl;

    cout << "----------------------------------------" << endl;
    cout << left << setw(20) << "Subject"
         << setw(10) << "Marks"
         << setw(5) << "Grade" << endl;
    cout << "----------------------------------------" << endl;

    // Display all subjects
    for (const auto& subject : subjects) {
        subject.display();
    }

    cout << "----------------------------------------" << endl;
    cout << fixed << setprecision(2);
    cout << "GPA     :  " << gpa << " / 4.0" << endl;
    cout << "Status  :  " << (isPassed ? "PASS" : "FAIL") << endl;
    cout << "========================================\n" << endl;
}

// Operator overloading - compare students by GPA
bool Result::operator>(const Result& other) const {
    return this->gpa > other.gpa;
}

bool Result::operator<(const Result& other) const {
    return this->gpa < other.gpa;
}

bool Result::operator==(const Result& other) const {
    return this->gpa == other.gpa;
}
