/*Write a program to define a class Rectangle with length and width. Implement a member function
that takes another Rectangle object and returns a new object with combined dimensions.*/
#include <iostream>
using namespace std;
class Rectangle {
private:
float length, width;
public:
Rectangle() {
length = 0;
width = 0;
}
Rectangle(float l, float w) {
length = l;
width = w;
}
void input() {
cout << "Enter length: ";
cin >> length;
cout << "Enter width: ";
cin >> width;
}
void display() const {
cout << "Length: " << length << ", Width: " << width << endl;
}
Rectangle combine(const Rectangle &r) const {
float newLength = length + r.length;
float newWidth = width + r.width;
return Rectangle(newLength, newWidth);
}
};
int main() {
Rectangle r1, r2, r3;
cout << "Enter Dimensions for Rectangle 1:" << endl;
r1.input();
cout << "\nEnter Dimensions for Rectangle 2:" << endl;
r2.input();
r3 = r1.combine(r2);
cout << "\nCombined Rectangle" << endl;
r3.display();
return 0;
}
