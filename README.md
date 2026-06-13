# 🎓 Academic Record Management System (C++)

A comprehensive, modular Console Application built in C++ that demonstrates the core principles of **Object-Oriented Programming (OOP)**. This system efficiently manages academic records, linking individuals, students, courses, and grading results.

---

## 🛠️ Project Architecture & File Structure

The project is structured modularly with separate interface (`.h`) and implementation (`.cpp`) files to ensure high maintainability and encapsulation.

### 📂 Core Components:
*   **`Person` (`Person.h` / `Person.cpp`)**: The base class containing fundamental identity attributes (e.g., Name, Age, ID) shared across institutional roles.
*   **`Student` (`Student.h` / `Student.cpp`)**: Derived from the `Person` class via **Inheritance**. It expands upon personal data by adding academic metrics like Roll Number, Semester, and Department.
*   **`Subject` (`Subject.h` / `Subject.cpp`)**: Manages course-specific configurations, including Subject Names, Unique Course Codes, and Maximum Assignable Marks.
*   **`Result` (`Result.h` / `Result.cpp`)**: Acts as the analytical bridge. It associates a `Student` with their registered `Subject` modules, computes obtained marks, and dynamically calculates Grades/GPA.
*   **`main.cpp`**: The primary controller and execution entry point where runtime objects are instantiated, workflows are tested, and data flows are validated.

### ⚙️ Development Environment (Included Settings):
*   **`.vscode/`**: Contains predefined workspace tasks (`tasks.json`), debug configurations (`launch.json`), compiler path links (`c_cpp_properties.json`), and custom local environment parameters (`settings.json`).

---

## ✨ Key OOP Concepts Demonstrated

1.  **Inheritance**: Leveraged heavily to extend the `Person` class into the specialized `Student` class, promoting code reusability.
2.  **Encapsulation**: All class attributes are kept strictly `private` or `protected`, exposing data safely only through explicit public getters, setters, and constructors.
3.  **Modular Abstraction**: Dividing the application logically into physical object models (`Person`, `Student`, `Subject`, `Result`) rather than keeping a monolithic code script.

---

## 🚀 Getting Started & Execution

### Prerequisites
Make sure you have a standard C++ compiler installed (GCC/G++ recommended).

### Compilation
To compile all the linked dependencies together into a single executable, run the following command in your terminal:

```bash
g++ main.cpp Person.cpp Student.cpp Subject.cpp Result.cpp -o academic_system
