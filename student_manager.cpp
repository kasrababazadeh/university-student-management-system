#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits> // for numeric_limits

#ifdef _WIN32
    #include <windows.h>
    void clearConsole() {
        system("cls");
    }
#else
    void clearConsole() {
        system("clear");
    }
#endif

using namespace std;

// Constants
const int MAX_STUDENTS = 100;
// const int MAX_SUBJECTS = 50; Note: unused const

// Class to represent a Student
class Student {
public:
    string firstName;
    string lastName;
    int studentNumber;
    double dynamicMark;
    double physicMark;
    double andisheMark;
    double azphysicMark;

    // Constructor to initialize student information
    Student(string firstName, string lastName, int studentNumber,
            double dynamicMark, double physicMark, double andisheMark, double azphysicMark)
        : firstName(firstName), lastName(lastName), studentNumber(studentNumber),
          dynamicMark(dynamicMark), physicMark(physicMark),
          andisheMark(andisheMark), azphysicMark(azphysicMark) {}

    // Calculate average
    double calculateAverage() const {
        return (dynamicMark * 4 + physicMark * 3 + andisheMark * 2 + azphysicMark) / 10;
    }
};

// Class to manage students
class StudentManager {
private:
    vector<Student> students;

public:
    // Add a student to the list
    void addStudent(const Student& student) {
        if (students.size() >= MAX_STUDENTS) {
            cerr << "Cannot add more students. Maximum limit reached.\n";
            return;
        }
        students.push_back(student);
    }

    // Display information for a student given their student number
    void displayStudentInfo(int studentNumber) const {
        for (const auto& student : students) {
            if (student.studentNumber == studentNumber) {
                cout << "Name: " << student.firstName << " " << student.lastName << endl;
                cout << "Student Number: " << studentNumber << endl;
                cout << "Average: " << student.calculateAverage() << endl;
                cout << "Dynamic Mark: " << student.dynamicMark << endl;
                cout << "Physic Mark: " << student.physicMark << endl;
                cout << "Andishe Mark: " << student.andisheMark << endl;
                cout << "Az Physic Mark: " << student.azphysicMark << endl;
                return;
            }
        }
        cout << "Student doesn't exist." << endl;
    }

    // Get number of students who flunked a subject
    int countFlunkedStudents(double passingMark, char subject) const {
        int count = 0;
        for (const auto& student : students) {
            double mark = 0;
            switch (subject) {
                case 'D': mark = student.dynamicMark; break;
                case 'P': mark = student.physicMark; break;
                case 'A': mark = student.andisheMark; break;
                case 'Z': mark = student.azphysicMark; break;
            }
            if (mark < passingMark) {
                count++;
            }
        }
        return count;
    }

    // Calculate max and min marks for a subject
    void displayMaxMinMarks(char subject) const {
        if (students.empty()) {
            cout << "No students available." << endl;
            return;
        }

        double max = -numeric_limits<double>::infinity();
        double min = numeric_limits<double>::infinity();

        for (const auto& student : students) {
            double mark = 0;
            switch (subject) {
                case 'D': mark = student.dynamicMark; break;
                case 'P': mark = student.physicMark; break;
                case 'A': mark = student.andisheMark; break;
                case 'Z': mark = student.azphysicMark; break;
            }
            if (mark > max) max = mark;
            if (mark < min) min = mark;
        }
        cout << "Maximum " << subject << "'s mark: " << max << endl;
        cout << "Minimum " << subject << "'s mark: " << min << endl;
    }

    // Calculate average mark for a subject
    double calculateSubjectAverage(char subject) const {
        double total = 0;
        int count = students.size();
        
        if (count == 0) return 0; // Avoid division by zero
        
        for (const auto& student : students) {
            double mark = 0;
            switch (subject) {
                case 'D': mark = student.dynamicMark; break;
                case 'P': mark = student.physicMark; break;
                case 'A': mark = student.andisheMark; break;
                case 'Z': mark = student.azphysicMark; break;
            }
            total += mark;
        }
        return total / count;
    }

    // Sort students by average mark
    void sortStudentsByAverage() {
        sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
            return a.calculateAverage() > b.calculateAverage(); // Sort in descending order
        });
    }
};

// User authentication and menu functions
void login(StudentManager& manager);
void displayMenu(StudentManager& manager);
void logout();
void enterStudentData(StudentManager& manager);
void displayAverageGrade(const StudentManager& manager);
void displayFlunkedStudents(const StudentManager& manager);
void displayMaxMinMarks(const StudentManager& manager);
void displaySubjectAverage(const StudentManager& manager);

// Main function
int main() {
    StudentManager manager;
    login(manager);
    return 0;
}

// Function to log in
void login(StudentManager& manager) {
    clearConsole();
    string username, password;
    // login details
    const string correctUsername = "admin";
    const string correctPassword = "5648";

    cout << "\t\t\t\t\t\t\tLOGIN\n";
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    if (username == correctUsername && password == correctPassword) {
        displayMenu(manager);
    } else {
        cout << "Invalid credentials. Please try again." << endl;
        login(manager);
    }
}

// Display the main menu
void displayMenu(StudentManager& manager) {
    char choice;
    do {
        clearConsole();
        cout << "1) Insert Student\n"
             << "2) Display Average Grade\n"
             << "3) Display Flunked Students\n"
             << "4) Display Max/Min Marks\n"
             << "5) Display Subject Average\n"
             << "6) Log Out\n"
             << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                enterStudentData(manager);
                break;
            case '2':
                displayAverageGrade(manager);
                break;
            case '3':
                displayFlunkedStudents(manager);
                break;
            case '4':
                displayMaxMinMarks(manager);
                break;
            case '5':
                displaySubjectAverage(manager);
                break;
            case '6':
                logout();
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != '6');
}

// Log out
void logout() {
    cout << "Logging out..." << endl;
    return; // safer than exit(0)
}

// Enter student data
void enterStudentData(StudentManager& manager) {
    clearConsole();
    string firstName, lastName;
    int studentNumber;
    double dynamicMark, physicMark, andisheMark, azphysicMark;

    cout << "Enter First Name: ";
    cin >> firstName;
    cout << "Enter Last Name: ";
    cin >> lastName;
    cout << "Enter Student Number: ";
    cin >> studentNumber;
    cout << "Enter Dynamic Mark: ";
    cin >> dynamicMark;
    cout << "Enter Physic Mark: ";
    cin >> physicMark;
    cout << "Enter Andishe Mark: ";
    cin >> andisheMark;
    cout << "Enter Az Physic Mark: ";
    cin >> azphysicMark;

    Student newStudent(firstName, lastName, studentNumber, dynamicMark, physicMark, andisheMark, azphysicMark);
    manager.addStudent(newStudent);
    cout << "Student added successfully!" << endl;
}

// Display average grades for all students
void displayAverageGrade(const StudentManager& manager) {
    clearConsole();
    int studentNumber;
    cout << "Enter student number: ";
    cin >> studentNumber;
    manager.displayStudentInfo(studentNumber);
    logout();
}

// Display the number of flunked students
void displayFlunkedStudents(const StudentManager& manager) {
    clearConsole();
    char subject;
    cout << "Enter subject (D for Dynamic, P for Physic, A for Andishe, Z for Az Physic): ";
    cin >> subject;
    double passingMark = 10.0;
    int count = manager.countFlunkedStudents(passingMark, subject);
    cout << "Number of flunked students in " << subject << ": " << count << endl;
    logout();
}

// Display max and min marks for a subject
void displayMaxMinMarks(const StudentManager& manager) {
    clearConsole();
    char subject;
    cout << "Enter subject (D for Dynamic, P for Physic, A for Andishe, Z for Az Physic): ";
    cin >> subject;
    manager.displayMaxMinMarks(subject);
    logout();
}

// Display average mark for a subject
void displaySubjectAverage(const StudentManager& manager) {
    clearConsole();
    char subject;
    cout << "Enter subject (D for Dynamic, P for Physic, A for Andishe, Z for Az Physic): ";
    cin >> subject;
    double average = manager.calculateSubjectAverage(subject);
    cout << "Average mark for " << subject << ": " << average << endl;
    logout();
}
