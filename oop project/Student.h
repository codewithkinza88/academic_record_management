#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
#include <string>
using namespace std;

class Student : public Person {
private:
    string rollNumber;
    string section;
    int semester;

public:
    // Constructors
    Student();
    Student(string name, int age, string gender, string rollNumber, string section, int semester);

    // Getters
    string getRollNumber() const;
    string getSection() const;
    int getSemester() const;

    // Setters
    void setRollNumber(string rollNumber);
    void setSection(string section);
    void setSemester(int semester);

    // Override display function
    void display() const override;

    // Destructor
    ~Student();
};

#endif
