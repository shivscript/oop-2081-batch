#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class Vehicle {
public:
    int id;
    char name[30];
    char brand[30];
    float rentPerDay;
    int available;

    void input() {
        cout << "Enter Vehicle ID: ";
        cin >> id;
        cout << "Enter Vehicle Name: ";
        cin.ignore();
        cin.getline(name, 30);
        cout << "Enter Vehicle Brand: ";
        cin.getline(brand, 30);
        cout << "Enter Rent per day: ";
        cin >> rentPerDay;
        available = 1;
    }

    void display() {
        cout << "ID: " << id
             << " | Name: " << name
             << " | Brand: " << brand
             << " | Rent/Day: " << rentPerDay
             << " | Available: " << (available ? "Yes" : "No") << endl;
    }

    int getID() {
        return id;
    }
};

class Booking {
public:
    int bookingID;
    char customerName[30];
    int vehicleID;
    int days;
    float totalCost;

    void input() {
        cout << "Enter Booking ID: ";
        cin >> bookingID;
        cout << "Enter Customer Name: ";
        cin.ignore();
        cin.getline(customerName, 30);
        cout << "Enter Vehicle ID to rent: ";
        cin >> vehicleID;
        cout << "Enter Number of Days: ";
        cin >> days;
    }

    void calculateCost(float rate) {
        totalCost = days * rate;
    }

    void display() {
        cout << "Booking ID: " << bookingID
             << " | Customer: " << customerName
             << " | Vehicle ID: " << vehicleID
             << " | Days: " << days
             << " | Total: Rs. " << totalCost << endl;
    }

    int getVehicleID() {
        return vehicleID;
    }

    int getBookingID() {
        return bookingID;
    }

    const char* getCustomerName() {
        return customerName;
    }
};

// Function Declarations
void adminMenu();
void customerMenu();
void addVehicle();
void viewVehicles();
void searchVehicle();
void removeVehicle();
void viewBookings();
void rentVehicle();
void returnVehicle();
void viewCustomerBookings();

int main() {
    int choice;
    do {
        cout << "\n====== VEHICLE RENTAL SYSTEM ======\n";
        cout << "1. Admin Login\n";
        cout << "2. Customer Portal\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            adminMenu();
            break;
        case 2:
            customerMenu();
            break;
        case 3:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid option!\n";
        }
    } while (choice != 3);

    return 0;
}

// ---------------- ADMIN ------------------

void adminMenu() {
     char username[30], password[30];
    char user[] = "Diwas";
    char pass[] = "pokhrel10";

    cout << "======= Vehicle Rental System =======\n";

    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    if (strcmp(username, user) == 0 && strcmp(password, pass) == 0) {
        int choice;
        do {
            cout << "\n------ Admin Menu ------\n";
            cout << "1. Add Vehicle\n";
            cout << "2. View Vehicles\n";
            cout << "3. Search Vehicle\n";
            cout << "4. Remove Vehicle\n";
            cout << "5. View Bookings\n";
            cout << "6. Back\n";
            cout << "Enter choice: ";
            cin >> choice;

            switch (choice) {
            case 1:
                addVehicle();
                break;
            case 2:
                viewVehicles();
                break;
            case 3:
                searchVehicle();
                break;
            case 4:
                removeVehicle();
                break;
            case 5:
                viewBookings();
                break;
            }
        } while (choice != 6);
    } else {
        cout << "Invalid username or password\n";
    }
}


void addVehicle() {
    Vehicle v;
    ofstream fout("vehicles.txt", ios::app | ios::binary);
    v.input();
    fout.write((char*)&v, sizeof(v));
    fout.close();
    cout << "Vehicle added successfully!\n";
}

void viewVehicles() {
    Vehicle v;
    ifstream fin("vehicles.txt", ios::binary);
    cout << "\n--- Vehicle List ---\n";
    while (fin.read((char*)&v, sizeof(v))) {
        v.display();
    }
    fin.close();
}

void searchVehicle() {
    Vehicle v;
    int id, found = 0;
    cout << "Enter vehicle ID to search: ";
    cin >> id;
    ifstream fin("vehicles.txt", ios::binary);
    while (fin.read((char*)&v, sizeof(v))) {
        if (v.getID() == id) {
            v.display();
            found = 1;
            break;
        }
    }
    fin.close();
    if (!found)
        cout << "Vehicle not found!\n";
}

void removeVehicle() {
    Vehicle v;
    int id;
    cout << "Enter vehicle ID to remove: ";
    cin >> id;

    ifstream fin("vehicles.txt", ios::binary);
    ofstream fout("temp.txt", ios::binary);

    while (fin.read((char*)&v, sizeof(v))) {
        if (v.getID() != id) {
            fout.write((char*)&v, sizeof(v));
        }
    }
    fin.close();
    fout.close();

    remove("vehicles.txt");
    rename("temp.txt", "vehicles.txt");

    cout << "Vehicle removed if it existed.\n";
}

void viewBookings() {
    Booking b;
    ifstream fin("bookings.txt", ios::binary);
    cout << "\n--- All Bookings ---\n";
    while (fin.read((char*)&b, sizeof(b))) {
        b.display();
    }
    fin.close();
}

// --------------- CUSTOMER -------------------

void customerMenu() {
    int choice;
    do {
        cout << "\n------ Customer Menu ------\n";
        cout << "1. View Vehicles\n";
        cout << "2. Rent Vehicle\n";
        cout << "3. Return Vehicle\n";
        cout << "4. View My Rentals\n";
        cout << "5. Back\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            viewVehicles();
            break;
        case 2:
            rentVehicle();
            break;
        case 3:
            returnVehicle();
            break;
        case 4:
            viewCustomerBookings();
            break;
        }
    } while (choice != 5);
}

void rentVehicle() {
    Vehicle v;
    Booking b;
    int id, found = 0;

    b.input();
    id = b.getVehicleID();

    fstream finout("vehicles.txt", ios::in | ios::out | ios::binary);
    while (finout.read((char*)&v, sizeof(v))) {
        if (v.getID() == id && v.available == 1) {
            v.available = 0;
            int pos = finout.tellg();
            finout.seekp(pos - sizeof(v));
            finout.write((char*)&v, sizeof(v));
            b.calculateCost(v.rentPerDay);

            ofstream fout("bookings.txt", ios::app | ios::binary);
            fout.write((char*)&b, sizeof(b));
            fout.close();

            cout << "Vehicle rented successfully!\n";
            found = 1;
            break;
        }
    }
    finout.close();
    if (!found)
        cout << "Vehicle not available!\n";
}

void returnVehicle() {
    Vehicle v;
    Booking b;
    int id, found = 0;

    cout << "Enter Booking ID to return: ";
    cin >> id;

    ifstream fin("bookings.txt", ios::binary);
    while (fin.read((char*)&b, sizeof(b))) {
        if (b.getBookingID() == id) {
            found = 1;
            break;
        }
    }
    fin.close();

    if (found) {
        fstream finout("vehicles.txt", ios::in | ios::out | ios::binary);
        while (finout.read((char*)&v, sizeof(v))) {
            if (v.getID() == b.getVehicleID()) {
                v.available = 1;
                int pos = finout.tellg();
                finout.seekp(pos - sizeof(v));
                finout.write((char*)&v, sizeof(v));
                break;
            }
        }
        finout.close();
        cout << "Vehicle returned successfully!\n";
    } else {
        cout << "Booking ID not found.\n";
    }
}

void viewCustomerBookings() {
    Booking b;
    char name[30];
    int found = 0;
    cout << "Enter your name to view your bookings: ";
    cin.ignore();
    cin.getline(name, 30);

    ifstream fin("bookings.txt", ios::binary);
    while (fin.read((char*)&b, sizeof(b))) {
        if (strcmp(b.getCustomerName(), name) == 0) {
            b.display();
            found = 1;
        }
    }
    fin.close();

    if (!found)
        cout << "No bookings found for this name.\n";
}