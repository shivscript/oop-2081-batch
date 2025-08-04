/*Write a program to access elements of a vector class with index operator.*/
#include <iostream>
using namespace std;
class Vector {
private:
int arr[5];
int size;
public:
Vector() : size(5) {
for (int i = 0; i < size; i++)
arr[i] = 0;
}
void input() {
cout << "Enter " << size << " elements: ";
for (int i = 0; i < size; i++)
cin >> arr[i];
}
void display() {
for (int i = 0; i < size; i++)
cout << arr[i] << " ";
cout << endl;
}

int& operator[](int index) {
if (index >= 0 && index < size)
return arr[index];
cout << "Index out of bounds!" << endl;
return arr[0];
}
};
int main() {
Vector v;
cout << "Input vector elements:\n";
v.input();
cout << "Original Vector: ";
v.display();
cout << "Accessing element at index 2: " << v[2] << endl;
v[2] = 100;
cout << "Vector after modifying index 2: ";
v.display();
return 0;
}
