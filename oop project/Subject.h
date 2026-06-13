#ifndef SUBJECT_H
#define SUBJECT_H

#include <string>
using namespace std;

class Subject {
private:
    string subjectName;
    int marksObtained;
    int totalMarks;

public:
    // Constructors
    Subject();
    Subject(string subjectName, int marksObtained, int totalMarks);

    // Getters
    string getSubjectName() const;
    int getMarksObtained() const;
    int getTotalMarks() const;

    // Setters
    void setSubjectName(string subjectName);
    void setMarksObtained(int marksObtained);
    void setTotalMarks(int totalMarks);

    // Calculate percentage
    double calculatePercentage() const;

    // Calculate letter grade
    char calculateGrade() const;

    // Calculate grade points (for GPA calculation)
    double getGradePoints() const;

    // Display subject details
    void display() const;
};

#endif
