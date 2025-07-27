#include <iostream>
using namespace std;

class Vehicle {
public:
    void drive() {
        cout << "Vehicle is driving." << endl;
    }
};

class Car : public Vehicle {
public:
    void start() {
        cout << "Car started." << endl;
    }
};

class ElectricCar : public Car {
public:
    void charge() {
        cout << "Electric car is charging." << endl;
    }
};

int main() {
    ElectricCar eCar;
    eCar.drive();
    eCar.start();
    eCar.charge();
    return 0;
}
