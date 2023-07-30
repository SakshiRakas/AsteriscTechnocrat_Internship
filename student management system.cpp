#include <iostream>
#include <string>
#include <vector>

struct Student {
    int rollNumber;
    std::string name;
    int age;
    // Add more student details here if needed
};

std::vector<Student> students;

// Function prototypes
void insertStudent();
void updateStudent();
void deleteStudent();
void showStudents();
void searchStudent();

int main() {
    char choice;

    do {
        std::cout << "Student Management System\n";
        std::cout << "1. Insert Student\n";
        std::cout << "2. Update Student\n";
        std::cout << "3. Delete Student\n";
        std::cout << "4. Show Students\n";
        std::cout << "5. Search Student\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case '1':
                insertStudent();
                break;
            case '2':
                updateStudent();
                break;
            case '3':
                deleteStudent();
                break;
            case '4':
                showStudents();
                break;
            case '5':
                searchStudent();
                break;
            case '6':
                std::cout << "Exiting program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != '6');

    return 0;
}

void insertStudent() {
    Student student;
    std::cout << "Enter Roll Number: ";
    std::cin >> student.rollNumber;
    std::cin.ignore(); // Ignore newline left in the buffer

    std::cout << "Enter Name: ";
    std::getline(std::cin, student.name);

    std::cout << "Enter Age: ";
    std::cin >> student.age;

    students.push_back(student);
    std::cout << "Student added successfully!\n";
}

void updateStudent() {
    int rollNumber;
    std::cout << "Enter Roll Number of the student to update: ";
    std::cin >> rollNumber;

    bool found = false;
    for (size_t i = 0; i < students.size(); ++i) {
        if (students[i].rollNumber == rollNumber) {
            std::cout << "Enter updated Name: ";
            std::cin.ignore(); // Ignore newline left in the buffer
            std::getline(std::cin, students[i].name);

            std::cout << "Enter updated Age: ";
            std::cin >> students[i].age;

            found = true;
            break;
        }
    }

    if (found) {
        std::cout << "Student information updated!\n";
    } else {
        std::cout << "Student not found.\n";
    }
}

void deleteStudent() {
    int rollNumber;
    std::cout << "Enter Roll Number of the student to delete: ";
    std::cin >> rollNumber;

    bool found = false;
    for (size_t i = 0; i < students.size(); ++i) {
        if (students[i].rollNumber == rollNumber) {
            students.erase(students.begin() + i);
            found = true;
            std::cout << "Student deleted!\n";
            break;
        }
    }

    if (!found) {
        std::cout << "Student not found.\n";
    }
}

void showStudents() {
    if (students.empty()) {
        std::cout << "No students found.\n";
        return;
    }

    std::cout << "Roll Number\tName\t\tAge\n";
    for (size_t i = 0; i < students.size(); ++i) {
        std::cout << students[i].rollNumber << "\t\t" << students[i].name << "\t\t" << students[i].age << "\n";
    }
}

void searchStudent() {
    int rollNumber;
    std::cout << "Enter Roll Number of the student to search: ";
    std::cin >> rollNumber;

    bool found = false;
    for (size_t i = 0; i < students.size(); ++i) {
        if (students[i].rollNumber == rollNumber) {
            std::cout << "Roll Number\tName\t\tAge\n";
            std::cout << students[i].rollNumber << "\t\t" << students[i].name << "\t\t" << students[i].age << "\n";
            found = true;
            break;
        }
    }

    if (!found) {
        std::cout << "Student not found.\n";
    }
}


