#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool equalsIgnoreCase(const string& a, const string& b) {
    if (a.size() != b.size()) return false;
    for (size_t i = 0; i < a.size(); ++i) {
        if (tolower(a[i]) != tolower(b[i])) return false;
    }
    return true;
}

// Base class
class Vehicle {
protected:
    string brand;
    string model;
    float rentalRatePerDay;
    bool isAvailable;

public:
    Vehicle(string b, string m, float rate)
        : brand(b), model(m), rentalRatePerDay(rate), isAvailable(true) {}

    virtual void displayDetails() const = 0;
    virtual float calculateRental(int days) const {
        return rentalRatePerDay * days;
    }

    string getModel() const {
        return model;
    }

    bool getAvailability() const {
        return isAvailable;
    }

    void setAvailability(bool status) {
        isAvailable = status;
    }

    virtual ~Vehicle() {}
};

// Derived class for Car
class Car : public Vehicle {
private:
    int passengerCapacity;

public:
    Car(string b, string m, float rate, int capacity)
        : Vehicle(b, m, rate), passengerCapacity(capacity) {}

    void displayDetails() const override {
        cout << "[Car] " << brand << " " << model
             << " | Rate/Day: Rs. " << rentalRatePerDay
             << " | Capacity: " << passengerCapacity
             << " | Available: " << (isAvailable ? "Yes" : "No") << endl;
    }
};

// Derived class for Bike
class Bike : public Vehicle {
private:
    float engineCC;

public:
    Bike(string b, string m, float rate, float cc)
        : Vehicle(b, m, rate), engineCC(cc) {}

    void displayDetails() const override {
        cout << "[Bike] " << brand << " " << model
             << " | Rate/Day: Rs. " << rentalRatePerDay
             << " | Engine: " << engineCC << "cc"
             << " | Available: " << (isAvailable ? "Yes" : "No") << endl;
    }
};

// Derived class for Truck
class Truck : public Vehicle {
private:
    float loadCapacity;

public:
    Truck(string b, string m, float rate, float load)
        : Vehicle(b, m, rate), loadCapacity(load) {}

    void displayDetails() const override {
        cout << "[Truck] " << brand << " " << model
             << " | Rate/Day: Rs. " << rentalRatePerDay
             << " | Load: " << loadCapacity << " tons"
             << " | Available: " << (isAvailable ? "Yes" : "No") << endl;
    }
};

// Rental Manager
class RentalManager {
private:
    vector<Vehicle*> vehicles;

public:
    void addVehicle(Vehicle* v) {
        vehicles.push_back(v);
    }

    void listAllVehicles() const {
        cout << "\n*****Vehicle List****" << endl;
        for (const auto& v : vehicles) {
            v->displayDetails();
        }
        cout << "--------------------" << endl;
    }
//This is for calculating the total rental cost based on rented day
    void rentVehicle(string model, int days) {
        for (auto& v : vehicles) {
            if (equalsIgnoreCase(v->getModel(), model) && v->getAvailability()) {
                float cost = v->calculateRental(days);
                v->setAvailability(false);
                cout << "Vehicle rented successfully. Total cost: Rs. " << cost << endl;
                return;
            }
        }
        cout << "Vehicle not available or not found!" << endl;
    }

    void returnVehicle(string model) {
        for (auto& v : vehicles) {
            if (equalsIgnoreCase(v->getModel(), model) && !v->getAvailability()) {
                v->setAvailability(true);
                cout << "Vehicle returned successfully!" << endl;
                return;
            }
        }
        cout << "Vehicle not found or already returned." << endl;
    }
//Use of Destructor
    ~RentalManager() {
        for (auto& v : vehicles) {
            delete v;
        }
    }
};

// Main Function
int main() {
    RentalManager rm;
    //The vehicle which is in Program
    rm.addVehicle(new Car("Toyota", "Corolla", 2500, 5));
    rm.addVehicle(new Car("BMW", "M3", 25000, 5));
    rm.addVehicle(new Bike("Yamaha", "R1", 9000, 998));
    rm.addVehicle(new Bike("Honda", "CBR1000RR-R", 15000, 998));
    rm.addVehicle(new Bike("BMW", "S1000RR", 12000, 998));
    rm.addVehicle(new Truck("Volvo", "FH", 5000, 2));

    int choice;
    string model;
    int days;

    do {
        cout << "\n*****Vehicle Rental System****" << endl;
        cout << "1. List all vehicles" << endl;
        cout << "2. Rent a vehicle" << endl;
        cout << "3. Return a vehicle" << endl;
        cout << "4. Exit" << endl;
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                rm.listAllVehicles();
                break;
            case 2:
                cout << "Enter vehicle model to rent: ";
                cin >> model;
                cout << "Enter number of rental days: ";
                cin >> days;
                rm.rentVehicle(model, days);
                break;
            case 3:
                cout << "Enter vehicle model to return: ";
                cin >> model;
                rm.returnVehicle(model);
                break;
            case 4:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 4);

    return 0;
}
