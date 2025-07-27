#include<iostream>
using namespace std;
class Vehicle {
    public:
    void drive (){
        cout<<"Vehicle is driving. "<<endl;
    }
};
class Car : public Vehicle {
    public:
    void start(){
        cout<<"Car started. "<<endl;  
    }
};
class ElectricCar : public Car {
    public:
    void charge(){
        cout<<"Electric Car is charging. "<<endl;
    }
};
int main(){
    ElectricCar car1;
    car1.charge();
    car1.start();
    car1.drive();
    return 0;
}