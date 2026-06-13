#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class Person {
private:
    string name;
    int age;
    string gender;

public:
    // Constructor
    Person();
    Person(string name, int age, string gender);

    // Getters
    string getName() const;
    int getAge() const;
    string getGender() const;

    // Setters
    void setName(string name);
    void setAge(int age);
    void setGender(string gender);

    // Virtual function for polymorphism
    virtual void display() const;

    // Virtual destructor
    virtual ~Person();
};

#endif
