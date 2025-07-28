#include <iostream>
using namespace std;

class Vehicle { public:
void drive() {
cout << "Vehicle is driving." << endl;
}
};

class Engine { public:
void start() {
cout << "Engine started." << endl;
}
};

class Car : public Vehicle, public Engine { public:
void run() {
start();
drive(); 
}
};

int main() {
Car c; c.run(); return 0;} 
