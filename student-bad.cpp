#include <cstring>
#include <iostream>

using namespace std;

// This is a badly implemented Student class.
// It stores the student's name as a C-style string.
// Unfortunately, because it only copies the pointer, but does
// not copy the contents of memory pointed at by the pointer,
// it is possible to alter student data from outside Student
// objects (even though the name is a private member variable!)

class Student {
    public:
        Student(int id, char *name) {
            cout << "Student constructor: Creating student " << id << " " << name << endl;
            // This is a new Student object, so we have to assign values to its member variables.
            //          Student s { 1, "Matt" };
            // Because this is a constructor, we receive values for the member variables
            // from the constructor arguments (or through defaults decided in advance).
            this->id = id;
            this->name = name;
        }

        Student(const Student &s) {
            cout << "Student copy constructor: Copying student " << s.id << " " << s.name << endl;
            // This is a new Student object, so we have to assign values to its member variables.
            //          Student s3 = s;
            // Because this is a copy constructor, we receive values for the member variables
            // from another Student object.
            id = s.id;
            name = s.name;
        }

        Student & operator=(const Student &s) {
            cout << "Student assignment operator: overwriting student " << id << " " << name;
            cout << " with student " << s.id << " " << s.name << endl;

            // This is an existing Student object in the process of being overwritten by another.
            //          Student s3 = s;
            //          ...
            //          s3 = s2;      <---
            // Because this is an assignment operator, we receive values for the member variables
            // from another Student object we are copying into ourselves.

            // Copy new values to overwrite our original member variables.
            id = s.id;
            name = s.name;

            // Assignment operators must return a reference to the object being assigned.
            // Because we have access to the "this" pointer, we can dereference it
            // and return it. It becomes a reference automatically as it is returned.
            return *this; 
        }

        void print() {
            cout << "Student ID " << id << ": " << name << endl;
        }

    private:
        char *name;
        int id;
};

int main() {
    char name1[] = "Matt";
    char name2[] = "Alice";

    // Create new Student objects (Invokes the Student constructor)
    Student s1 { 1, name1 };
    Student s2 {2, name2 };

    // Create a new Student object directly as a copy of another
    // (Invokes the copy constructor)
    Student s3 = s1;

    // Overwrite an existing Student object with the contents of
    // another (Invokes the assignment operator)
    s3 = s2;

    // Because the Student class only copies the "name" pointer, but does not
    // copy the contents of memory pointed at by the "name" pointer, we can
    // alter Alice's name here:

    s1.print();
    s2.print();
    s3.print();

    name2[0] = 'Z';

    s1.print();
    s2.print();
    s3.print();
}