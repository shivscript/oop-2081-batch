/*Create an abstract base class Animal with a pure virtual function speak().
Create derived classes Dog and Cat that implement the speak() method. Implement
a main() function to demonstrate the use of these classes.*/
#include <iostream>
using namespace std;
class Animal {
public:
    virtual void speak() = 0; 
    virtual ~Animal() {}     
};
class Dog : public Animal {
public:
    void speak() override {
        cout << "Woof! Woof!" << endl;
    }
};
class Cat : public Animal {
public:
    void speak() override {
        cout << "Meow! Meow!" << endl;
    }
};
int main() {
    Animal* a1 = new Dog();
    Animal* a2 = new Cat();
    a1->speak();  
    a2->speak();  
    delete a1;
    delete a2;
    return 0;
}
