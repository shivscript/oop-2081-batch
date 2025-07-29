/*Write a program to demonstrate a friend function that accesses private data from two different
classes and adds their values.*/
#include <iostream>
using namespace std;
class ClassB;
class ClassA {
private:
int valueA;
public:
ClassA(int a = 0) {
valueA = a;
}
friend int addValues(ClassA, ClassB);
};
class ClassB {
private:
int valueB;
public:
ClassB(int b = 0) {
valueB = b;
}
friend int addValues(ClassA, ClassB);
};
int addValues(ClassA a, ClassB b) {
return a.valueA + b.valueB;
}
int main() {
int x, y;
cout << "Enter value for ClassA: ";
cin >> x;
cout << "Enter value for ClassB: ";
cin >> y;
ClassA objA(x);
ClassB objB(y);
int result = addValues(objA, objB);
cout << "\nSum of values (ClassA + ClassB): " << result << endl;
return 0;
}
