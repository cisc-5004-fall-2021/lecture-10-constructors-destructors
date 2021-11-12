#include <cstring>
#include <iostream>

using namespace std;

// This is a correctly implemented Student class.
// It stores the student's name as a C-style string.
// Because C-style strings are really pointers, the
// Student class uses built-in C string functions to make
// a copy of the region of memory pointed at by the name
// pointer.
class Student {
    public:
        Student(int id, const char *name) {
            cout << "Student constructor: Creating student " << id << " " << name << endl;
            // This is a new Student object, so we have to assign values to its member variables.
            //          Student s { 1, "Matt" };
            // Because this is a constructor, we receive values for the member variables
            // from the constructor arguments (or through defaults decided in advance).
            this->id = id;

            // Allocate space for a new name large enough to contain it.
            // The "strlen()" function (from the "cstring" header) returns
            // the number of characters in a string prior to the null terminator.
            this->name = new char[strlen(name)+1];

            // Copy the characters from the constructor argument into our newly
            // allocated space. "strcpy()" is also from the "cstring" header.
            strcpy(this->name, name);
        }

        Student(const Student &s) {
            cout << "Student copy constructor: Copying student " << s.id << " " << s.name << endl;
            // This is a new Student object, so we have to assign values to its member variables.
            //          Student s3 = s;
            // Because this is a copy constructor, we receive values for the member variables
            // from another Student object.
            id = s.id;
            name = new char[strlen(s.name)+1];
            strcpy(this->name, s.name);
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

            // Because we are overwriting ourselves, we have to clean up any memory we previously
            // allocated to avoid memory leaks. Here, we free the memory associated with our
            // name member variable so we can replace it later.
            delete[] this->name;

            // Copy new values to overwrite our original member variables.
            id = s.id;
            name = new char[strlen(s.name)+1];
            strcpy(name, s.name);

            // Assignment operators must return a reference to the object being assigned.
            // Because we have access to the "this" pointer, we can dereference it
            // and return it. It becomes a reference automatically as it is returned.
            return *this; 
        }

        ~Student() {
            cout << "Student destructor: destroying student object " << id << " " << name << endl;
            // This is a Student object in the process of being destroyed.
            // We have to clean up any memory we previously allocated to avoid memory leaks.
            delete [] name;
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

    s1.print();
    s2.print();
    s3.print();
}