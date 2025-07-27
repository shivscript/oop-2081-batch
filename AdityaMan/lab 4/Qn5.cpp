#include <iostream>
using namespace std;
class Vehicle {
public:
void drive() {
cout << "Vehicle is driving." << endl;
}
};
class Engine {
public:
void start() {
cout << "Engine started." << endl;
}
};
class Car : public Vehicle, public Engine {
public:
void run() {
start();
drive();
}
};
class ElectricCar: public Car{
    public:
    void electric(){
        run();
    }
};
int main() {
Car c;
ElectricCar ec;
cout<<"FOR NORMAL CAR"<<endl;
c.run();
cout<<"FOR ELECTRIC CAR"<<endl;
ec.electric();
return 0;}
