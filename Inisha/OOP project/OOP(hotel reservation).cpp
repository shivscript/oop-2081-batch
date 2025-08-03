#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Room {
    int roomNo;
    string type;
    bool isOccupied;
    float rate;
};

struct Customer {
    int customerID;
    string name, checkInDate;
    int roomNo;
};

Room rooms[4] = {
    {101, "AC", false, 3000},
    {102, "Non-AC", false, 2000},
    {201, "Suite", false, 5000},
    {202, "AC", false, 3000}
};

void showAvailableRooms() {
    cout << "\nAvailable Rooms:\n";
    for (int i = 0; i < 4; i++) {
        if (!rooms[i].isOccupied) {
            cout << "Room No: " << rooms[i].roomNo << ", Type: " << rooms[i].type << ", Rate: Rs. " << rooms[i].rate << "/night\n";
        }
    }
}

void saveCustomerToFile(const Customer &c) {
    ofstream out("customer.txt", ios::app);
    out << c.customerID << ',' << c.name << ',' << c.checkInDate << ','  << ',' << c.roomNo << '\n';
    out.close();
}

void bookRoom() {
    Customer c;
    cout << "Enter Customer ID: "; cin >> c.customerID;
    cin.ignore();
    cout << "Enter Name: "; getline(cin, c.name);
    cout << "Enter Check-in Date: "; getline(cin, c.checkInDate);


    showAvailableRooms();
    cout << "Enter Room No to book: ";
    cin >> c.roomNo;

    for (int i = 0; i < 4; i++) {
        if (rooms[i].roomNo == c.roomNo && !rooms[i].isOccupied) {
            rooms[i].isOccupied = true;
            saveCustomerToFile(c);
            cout << "Room booked successfully!\n";
            return;
        }
    }
    cout << "Room is not available or doesn't exist.\n";
}

void checkOut() {
    int roomNumber, totalNight;
    cout << "Enter Room No for checkout: ";
    cin >> roomNumber;
     cout << "Enter the total night stayed: ";
    cin >> totalNight;

    for (int i = 0; i < 4; i++) {
        if (rooms[i].roomNo == roomNumber && rooms[i].isOccupied) {
            rooms[i].isOccupied = false;
            cout << "\nGenerating Invoice...\n";
            cout << "Room No: " << rooms[i].roomNo << ", Type: " << rooms[i].type << ", Total: Rs. " << rooms[i].rate*totalNight << "\n";
            cout << "Checked out successfully.\n";
            return;
        }
    }
    cout << "Room not found or already vacant.\n";
}

void viewCustomers() {
    ifstream in("customers.txt");
    string line;
    cout << "\nCustomer Records:\n";
    while (getline(in, line)) {
        cout << line << endl;
    }
    in.close();
}

int main() {
    int choice;
    do {
        cout << "\n--- Hotel Reservation Menu ---\n";
        cout << "1. View Available Rooms\n2. Book Room\n3. View Customers\n4. Checkout\n0. Exit\n";
        cout << "Enter choice: "; cin >> choice;

        switch (choice) {
            case 1: showAvailableRooms(); break;
            case 2: bookRoom(); break;
            case 3: viewCustomers(); break;
            case 4: checkOut(); break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}

