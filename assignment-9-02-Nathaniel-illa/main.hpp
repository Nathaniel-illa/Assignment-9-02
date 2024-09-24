#include <iostream>
#include <fstream>
#include <cstring> // for strcmp
using namespace std;

struct Student {
    int id;
    char name[50];
    char major[50];
    Student *next; // Pointer to the next Student
};

Student *makeStudent();
void printStudent(Student *head);

Student *makeStudent() {
    ifstream infile("students.txt");
    if (!infile) {
        cerr << "Error opening file!" << endl;
        return nullptr;
    }

    Student *head = nullptr; // Pointer to the head of the list
    Student *tail = nullptr; // Pointer to the last student

    while (true) {
        Student *newStudent = new Student; // Allocate memory for a new student
        infile >> newStudent->id >> newStudent->name >> newStudent->major;

        if (infile.eof()) {
            delete newStudent; // Clean up if EOF is reached without valid data
            break;
        }

        newStudent->next = nullptr; // Initialize the next pointer

        if (head == nullptr) {
            head = newStudent; // First student
            tail = newStudent; // Tail also points to the first student
        } else {
            tail->next = newStudent; // Link the new student to the last one
            tail = newStudent; // Move the tail pointer
        }
    }

    infile.close();
    return head; // Return the head of the linked list
}

void printStudent(Student *head) {
    Student *tmp = head;
    while (tmp != nullptr) {
        cout << tmp->id << "\t" << tmp->name << "\t" << tmp->major << endl;
        tmp = tmp->next;
    }
}