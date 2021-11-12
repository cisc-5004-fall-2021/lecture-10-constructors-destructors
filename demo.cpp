#include <iostream>

using namespace std;

// Run this code to see when the constructor and destructor are called.
// The file includes alternate ways of creating the Demo object - try
// using them instead of the declaration on line 21 to see what happens.

class Demo {
    public:
        Demo() {
            cout << "Constructor" << endl;
        }
        ~Demo() {
            cout << "Destructor" << endl;
        }
};

// Demo d;
int main() {
    Demo d;

    /* Demo *d = new Demo;
    delete d */

    return 0;
}