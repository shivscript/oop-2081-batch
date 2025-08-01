#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

struct Room {
    int number;
    string type;
    int price;
    bool booked;
    string guestName;
};

class HotelManagementSystem {
private:
    vector<Room> rooms;
    const string adminUser = "nawnit";
    const string adminPass = "paudel";
    bool adminLoggedIn = false;

    void pause() {
        cout << "\nPress Enter to continue...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    void clearInput() {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    void showRooms(bool showBooked = false) {
        cout << "\nRooms List:\n";
        cout << "-----------------------------------------\n";
        cout << "Room No\tType\tPrice\tStatus\t\tGuest\n";
        cout << "-----------------------------------------\n";
        for (auto &room : rooms) {
            cout << room.number << "\t" << room.type << "\t$" << room.price << "\t";
            if (room.booked) {
                cout << "Booked\t\t" << room.guestName << "\n";
            } else {
                cout << "Available\t-\n";
            }
        }
        cout << "-----------------------------------------\n";
    }

    void bookRoom() {
        int roomNo;
        string guest;
        cout << "\nEnter Room Number to book: ";
        cin >> roomNo;
        clearInput();

        auto it = find_if(rooms.begin(), rooms.end(), [roomNo](Room &r) { return r.number == roomNo; });
        if (it == rooms.end()) {
            cout << "Room number " << roomNo << " not found.\n";
            pause();
            return;
        }

        if (it->booked) {
            cout << "Room " << roomNo << " is already booked by " << it->guestName << ".\n";
            pause();
            return;
        }

        cout << "Enter your name: ";
        getline(cin, guest);
        if (guest.empty()) {
            cout << "Guest name cannot be empty.\n";
            pause();
            return;
        }

        it->booked = true;
        it->guestName = guest;
        cout << "Room " << roomNo << " successfully booked for " << guest << ".\n";
        pause();
    }

    void checkOutRoom() {
        int roomNo;
        cout << "\nEnter Room Number to check out: ";
        cin >> roomNo;
        clearInput();

        auto it = find_if(rooms.begin(), rooms.end(), [roomNo](Room &r) { return r.number == roomNo; });
        if (it == rooms.end()) {
            cout << "Room number " << roomNo << " not found.\n";
            pause();
            return;
        }

        if (!it->booked) {
            cout << "Room " << roomNo << " is not currently booked.\n";
            pause();
            return;
        }

        cout << "Checking out guest " << it->guestName << " from room " << roomNo << ".\n";
        it->booked = false;
        it->guestName.clear();
        pause();
    }

    bool adminLogin() {
        string user, pass;
        cout << "\n--- Admin Login ---\n";
        cout << "Username: ";
        getline(cin, user);
        cout << "Password: ";
        getline(cin, pass);

        if (user == adminUser && pass == adminPass) {
            adminLoggedIn = true;
            cout << "Login successful!\n";
            pause();
            return true;
        } else {
            cout << "Invalid username or password.\n";
            pause();
            return false;
        }
    }

    void adminDashboard() {
        while (adminLoggedIn) {
            system("clear"); // or "cls" on Windows
            cout << "\n--- Admin Dashboard ---\n";
            showRooms(true);
            cout << "\nOptions:\n";
            cout << "1. Check Out Room\n";
            cout << "2. Logout\n";
            cout << "Choose an option: ";
            int choice;
            cin >> choice;
            clearInput();

            if (choice == 1) {
                checkOutRoom();
            } else if (choice == 2) {
                adminLoggedIn = false;
                cout << "Logged out from admin panel.\n";
                pause();
                break;
            } else {
                cout << "Invalid option.\n";
                pause();
            }
        }
    }

public:
    HotelManagementSystem() {
        rooms = {
            {101, "Single", 50, false, ""},
            {102, "Double", 80, false, ""},
            {103, "Suite", 150, false, ""},
            {104, "Single", 50, false, ""},
            {105, "Double", 80, false, ""}
        };
    }

    void run() {
        while (true) {
            system("clear"); // Use "cls" if on Windows
            cout << "=== Hotel Management System ===\n";
            cout << "1. View Rooms\n";
            cout << "2. Book a Room\n";
            cout << "3. Admin Login\n";
            cout << "4. Exit\n";
            cout << "Choose an option: ";
            int choice;
            cin >> choice;
            clearInput();

            if (choice == 1) {
                showRooms();
                pause();
            } else if (choice == 2) {
                bookRoom();
            } else if (choice == 3) {
                if (adminLogin()) {
                    adminDashboard();
                }
            } else if (choice == 4) {
                cout << "Thank you for using the system. Goodbye!\n";
                break;
            } else {
                cout << "Invalid choice! Try again.\n";
                pause();
            }
        }
    }
};

int main() {
    HotelManagementSystem h;
    h.run();
    return 0;
}
