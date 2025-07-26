#include<iostream>
using namespace std;
class Vehicle {
    public:
    void move (){
        cout<<"Vehicle is moving. "<<endl;
    }
};
class Engine {
    public:
    void run (){
        cout<<"Engine running. "<<endl;
    }
};
class Car1 : public Vehicle, public Engine {
    public:
    void ready(){
        run();
        cout<<"First car is ready to go. "<<endl;  
        move();
    }
};
class Car2 : public Vehicle, public Engine {
    public:
    void ready(){
        run();
        cout<<"Second car is ready to go. "<<endl;  
        move();
    }
};
int main(){
    Car1 c1;
    Car2 c2;
    c1.ready();
    c2.ready();
    return 0;
}