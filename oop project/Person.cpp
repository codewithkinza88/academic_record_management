#include "Person.h"
#include <iostream>
using namespace std;

// Default Constructor
Person::Person() {
    name = "";
    age = 0;
    gender = "";
}

// Parameterized Constructor
Person::Person(string name, int age, string gender) {
    this->name = name;
    this->age = age;
    this->gender = gender;
}

// Getters
string Person::getName() const {
    return name;
}

int Person::getAge() const {
    return age;
}

string Person::getGender() const {
    return gender;
}

// Setters
void Person::setName(string name) {
    this->name = name;
}

void Person::setAge(int age) {
    this->age = age;
}

void Person::setGender(string gender) {
    this->gender = gender;
}

// Display function
void Person::display() const {
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Gender: " << gender << endl;
}

// Destructor
Person::~Person() {
    // Cleanup if needed
}
