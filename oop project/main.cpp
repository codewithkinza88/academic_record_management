#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <iomanip>
#include "Person.h"
#include "Student.h"
#include "Subject.h"
#include "Result.h"

using namespace std;

// Global vector to store all results
vector<Result> allResults;

// Function prototypes
void displayMenu();
void addNewStudent();
void recordMarks();
void displayResultCard();
void viewAllStudents();
void compareStudents();
void clearInputBuffer();

int main() {
    int choice;

    cout << "\n========================================" << endl;
    cout << "  STUDENT RESULT MANAGEMENT SYSTEM" << endl;
    cout << "========================================\n" << endl;

    while (true) {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        // Input validation
        if (cin.fail()) {
            clearInputBuffer();
            cout << "\nInvalid input! Please enter a number.\n" << endl;
            continue;
        }

        clearInputBuffer();

        switch (choice) {
            case 1:
                addNewStudent();
                break;
            case 2:
                recordMarks();
                break;
            case 3:
                displayResultCard();
                break;
            case 4:
                viewAllStudents();
                break;
            case 5:
                compareStudents();
                break;
            case 6:
                cout << "\nThank you for using the system!" << endl;
                cout << "Exiting...\n" << endl;
                return 0;
            default:
                cout << "\nInvalid choice! Please try again.\n" << endl;
        }
    }

    return 0;
}

// Display main menu
void displayMenu() {
    cout << "========================================" << endl;
    cout << "              MAIN MENU" << endl;
    cout << "========================================" << endl;
    cout << "1. Add New Student" << endl;
    cout << "2. Record Subject Marks" << endl;
    cout << "3. Display Result Card" << endl;
    cout << "4. View All Students" << endl;
    cout << "5. Compare Students by GPA" << endl;
    cout << "6. Exit" << endl;
    cout << "========================================" << endl;
}

// Clear input buffer
void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Add a new student
void addNewStudent() {
    string name, rollNumber, section, gender;
    int age, semester;

    cout << "\n--- Add New Student ---" << endl;

    cout << "Enter Name: ";
    getline(cin, name);

    cout << "Enter Roll Number: ";
    getline(cin, rollNumber);

    // Check if student already exists
    for (const auto& result : allResults) {
        if (result.getStudent().getRollNumber() == rollNumber) {
            cout << "\nError: Student with roll number " << rollNumber << " already exists!\n" << endl;
            return;
        }
    }

    cout << "Enter Section: ";
    getline(cin, section);

    cout << "Enter Semester: ";
    cin >> semester;

    cout << "Enter Age: ";
    cin >> age;

    clearInputBuffer();

    cout << "Enter Gender: ";
    getline(cin, gender);

    // Create student object
    Student student(name, age, gender, rollNumber, section, semester);

    // Create result object
    Result result(student);
    allResults.push_back(result);

    cout << "\nStudent added successfully!\n" << endl;
}

// Record marks for a student
void recordMarks() {
    if (allResults.empty()) {
        cout << "\nNo students registered yet! Please add a student first.\n" << endl;
        return;
    }

    string rollNumber;
    cout << "\n--- Record Subject Marks ---" << endl;
    cout << "Enter Student Roll Number: ";
    getline(cin, rollNumber);

    // Find student
    int studentIndex = -1;
    for (size_t i = 0; i < allResults.size(); i++) {
        if (allResults[i].getStudent().getRollNumber() == rollNumber) {
            studentIndex = i;
            break;
        }
    }

    if (studentIndex == -1) {
        cout << "\nError: Student with roll number " << rollNumber << " not found!\n" << endl;
        return;
    }

    int numSubjects;
    cout << "How many subjects to add (max 5): ";
    cin >> numSubjects;

    if (numSubjects < 1 || numSubjects > 5) {
        cout << "\nError: Number of subjects must be between 1 and 5!\n" << endl;
        clearInputBuffer();
        return;
    }

    clearInputBuffer();

    for (int i = 0; i < numSubjects; i++) {
        string subjectName;
        int marksObtained, totalMarks;

        cout << "\nSubject " << (i + 1) << ":" << endl;
        cout << "Enter Subject Name: ";
        getline(cin, subjectName);

        cout << "Enter Marks Obtained: ";
        cin >> marksObtained;

        cout << "Enter Total Marks: ";
        cin >> totalMarks;

        clearInputBuffer();

        // Validate marks
        if (marksObtained < 0 || marksObtained > totalMarks) {
            cout << "Invalid marks! Marks obtained cannot be negative or greater than total marks." << endl;
            i--; // Retry this subject
            continue;
        }

        // Create subject and add to result
        Subject subject(subjectName, marksObtained, totalMarks);
        allResults[studentIndex].addSubject(subject);
    }

    cout << "\nMarks recorded successfully!\n" << endl;
}

// Display result card for a student
void displayResultCard() {
    if (allResults.empty()) {
        cout << "\nNo students registered yet!\n" << endl;
        return;
    }

    string rollNumber;
    cout << "\n--- Display Result Card ---" << endl;
    cout << "Enter Student Roll Number: ";
    getline(cin, rollNumber);

    // Find student
    for (const auto& result : allResults) {
        if (result.getStudent().getRollNumber() == rollNumber) {
            if (result.getSubjects().empty()) {
                cout << "\nNo marks recorded for this student yet!\n" << endl;
                return;
            }
            result.generateResultCard();
            return;
        }
    }

    cout << "\nError: Student with roll number " << rollNumber << " not found!\n" << endl;
}

// View all registered students
void viewAllStudents() {
    if (allResults.empty()) {
        cout << "\nNo students registered yet!\n" << endl;
        return;
    }

    cout << "\n========================================" << endl;
    cout << "      ALL REGISTERED STUDENTS" << endl;
    cout << "========================================" << endl;

    for (size_t i = 0; i < allResults.size(); i++) {
        Student student = allResults[i].getStudent();
        cout << "\n" << (i + 1) << ". " << student.getName() << endl;
        cout << "   Roll Number: " << student.getRollNumber() << endl;
        cout << "   Section: " << student.getSection() << endl;
        cout << "   Semester: " << student.getSemester() << endl;

        if (!allResults[i].getSubjects().empty()) {
            cout << "   GPA: " << fixed << setprecision(2) << allResults[i].getGPA() << " / 4.0" << endl;
            cout << "   Status: " << (allResults[i].getPassStatus() ? "PASS" : "FAIL") << endl;
        } else {
            cout << "   Status: Marks not recorded yet" << endl;
        }
    }

    cout << "\n========================================\n" << endl;
}

// Compare two students by GPA
void compareStudents() {
    if (allResults.size() < 2) {
        cout << "\nNeed at least 2 students with recorded marks to compare!\n" << endl;
        return;
    }

    string roll1, roll2;
    cout << "\n--- Compare Students by GPA ---" << endl;
    cout << "Enter first student's roll number: ";
    getline(cin, roll1);

    cout << "Enter second student's roll number: ";
    getline(cin, roll2);

    // Find both students
    Result* result1 = nullptr;
    Result* result2 = nullptr;

    for (auto& result : allResults) {
        if (result.getStudent().getRollNumber() == roll1) {
            result1 = &result;
        }
        if (result.getStudent().getRollNumber() == roll2) {
            result2 = &result;
        }
    }

    if (result1 == nullptr || result2 == nullptr) {
        cout << "\nError: One or both students not found!\n" << endl;
        return;
    }

    if (result1->getSubjects().empty() || result2->getSubjects().empty()) {
        cout << "\nError: Both students must have recorded marks for comparison!\n" << endl;
        return;
    }

    cout << "\n========================================" << endl;
    cout << "         COMPARISON RESULT" << endl;
    cout << "========================================" << endl;
    cout << "Student 1: " << result1->getStudent().getName() << endl;
    cout << "GPA: " << fixed << setprecision(2) << result1->getGPA() << " / 4.0" << endl;
    cout << "\nStudent 2: " << result2->getStudent().getName() << endl;
    cout << "GPA: " << fixed << setprecision(2) << result2->getGPA() << " / 4.0" << endl;
    cout << "----------------------------------------" << endl;

    if (*result1 > *result2) {
        cout << result1->getStudent().getName() << " has a higher GPA!" << endl;
    } else if (*result1 < *result2) {
        cout << result2->getStudent().getName() << " has a higher GPA!" << endl;
    } else {
        cout << "Both students have the same GPA!" << endl;
    }

    cout << "========================================\n" << endl;
}
