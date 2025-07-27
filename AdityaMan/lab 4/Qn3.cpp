#include <iostream>
using namespace std;
class Animal {
public:
void speak() {
cout << "Animal speaks." << endl;
}};
class Dog : public Animal {
public:
void speak() {
cout << "Dog barks." << endl;
}};
class Cat : public Animal {
public:
void speak() {
cout << "Cat meows." << endl;
}};
int main() {
Dog d;
Cat c;
d.speak();
c.speak();
return 0;
}
