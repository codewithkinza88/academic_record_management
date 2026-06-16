#include "Subject.h"
#include <iostream>
#include <iomanip>
using namespace std;

// Default Constructor
Subject::Subject() {
    subjectName = "";
    marksObtained = 0;
    totalMarks = 100;
}

// Parameterized Constructor
Subject::Subject(string subjectName, int marksObtained, int totalMarks) {
    this->subjectName = subjectName;
    this->marksObtained = marksObtained;
    this->totalMarks = totalMarks;
}

// Getters
string Subject::getSubjectName() const {
    return subjectName;
}

int Subject::getMarksObtained() const {
    return marksObtained;
}

int Subject::getTotalMarks() const {
    return totalMarks;
}

// Setters
void Subject::setSubjectName(string subjectName) {
    this->subjectName = subjectName;
}

void Subject::setMarksObtained(int marksObtained) {
    this->marksObtained = marksObtained;
}

void Subject::setTotalMarks(int totalMarks) {
    this->totalMarks = totalMarks;
}

// Calculate percentage
double Subject::calculatePercentage() const {
    if (totalMarks == 0) return 0.0;
    return (static_cast<double>(marksObtained) / totalMarks) * 100.0;
}

// Calculate letter grade based on percentage
char Subject::calculateGrade() const {
    double percentage = calculatePercentage();

    if (percentage >= 85) return 'A';
    else if (percentage >= 70) return 'B';
    else if (percentage >= 60) return 'C';
    else if (percentage >= 50) return 'D';
    else return 'F';
}

// Calculate grade points for GPA (4.0 scale)
double Subject::getGradePoints() const {
    char grade = calculateGrade();

    switch(grade) {
        case 'A': return 4.0;
        case 'B': return 3.0;
        case 'C': return 2.0;
        case 'D': return 1.0;
        case 'F': return 0.0;
        default: return 0.0;
    }
}

// Display subject details
void Subject::display() const {
    cout << left << setw(20) << subjectName;
    cout << setw(10) << (to_string(marksObtained) + "/" + to_string(totalMarks));
    cout << setw(5) << calculateGrade() << endl;
}
