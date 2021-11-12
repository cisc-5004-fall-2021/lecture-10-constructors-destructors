#include <iostream>
#include <vector>

using namespace std;

// This code demonstrates the proper usage of a destructor.
// If your class dynamically allocates memory as part of its
// lifecycle, you must free that memory whenever an object
// of that class is destroyed. Otherwise, the memory will never
// be deallocated, and you will have a memory leak!

struct Room { int length; int width; };

class House {
    public:
        House(int totalRooms) {
            this->totalRooms = totalRooms;

            // Allocate sufficient space to store the desired number of rooms.
            // This memory can only be freed with the "delete" operator!
            this->rooms = new Room[totalRooms];
            this->roomCount = 0;
        }

        ~House() {
            // Destructor - called as a House object is destroyed.
            // This is our only opportunity to free the memory
            // we allocated in the constructor!
            delete [] rooms;
        }

        void addRoom(int length, int width) {
            if(roomCount < totalRooms) {
                rooms[roomCount] = Room{length, width};
                roomCount++;
            }
        }

        int sqft() {
            int total = 0;

            for (int i = 0; i < roomCount; i++) {
                total += rooms[i].length * rooms[i].width;
            }

            return total;
        }

    private:
        int totalRooms;
        int roomCount;
        Room *rooms;
};

int main() {
    House h {3};
    h.addRoom(10,20);
    h.addRoom(20,30);
    h.addRoom(15,23);

    cout << "Square footage: " << h.sqft() << endl;
}