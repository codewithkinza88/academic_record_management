#include "Student.h"
#include <iostream>
using namespace std;

// Default Constructor
Student::Student() : Person() {
    rollNumber = "";
    section = "";
    semester = 0;
}

// Parameterized Constructor
Student::Student(string name, int age, string gender, string rollNumber, string section, int semester)
    : Person(name, age, gender) {
    this->rollNumber = rollNumber;
    this->section = section;
    this->semester = semester;
}

// Getters
string Student::getRollNumber() const {
    return rollNumber;
}

string Student::getSection() const {
    return section;
}

int Student::getSemester() const {
    return semester;
}

// Setters
void Student::setRollNumber(string rollNumber) {
    this->rollNumber = rollNumber;
}

void Student::setSection(string section) {
    this->section = section;
}

void Student::setSemester(int semester) {
    this->semester = semester;
}

// Override display function
void Student::display() const {
    cout << "Name: " << getName() << endl;
    cout << "Roll Number: " << rollNumber << endl;
    cout << "Section: " << section << endl;
    cout << "Semester: " << semester << endl;
    cout << "Age: " << getAge() << endl;
    cout << "Gender: " << getGender() << endl;
}

// Destructor
Student::~Student() {
    // Cleanup if needed
}
