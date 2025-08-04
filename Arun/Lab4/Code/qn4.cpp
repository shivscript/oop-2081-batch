/*Write a program that demonstrates default, parameterized, and copy constructors. Use the this
pointer to calculate the midpoint between two points.*/
#include <iostream>
using namespace std;
class Point {
private:
float x, y;
public:
Point() {
x = 0;
y = 0;
cout << "Default constructor called.\n";
}
Point(float a, float b) {
x = a;
y = b;
cout << "Parameterized constructor called for (" << x << ", " << y << ")\n";
}
Point(const Point &p) {
x = p.x;
y = p.y;
cout << "Copy constructor called for (" << x << ", " << y << ")\n";
}
Point midpoint(const Point &p) const {
float midX = (this->x + p.x) / 2;
float midY = (this->y + p.y) / 2;
return Point(midX, midY);
}
void input() {
cout << "Enter x and y coordinates: ";
cin >> x >> y;
}
void display() const {
cout << "(" << x << ", " << y << ")" << endl;
}
};
int main() {
cout << "***Enter Coordinates for Point 1***" << endl;
Point p1;
p1.input();
cout << "***Enter Coordinates for Point 2***" << endl;
Point p2;
p2.input();
cout << "--- Copying Point 1 to Point 3 ---" << endl;
Point p3 = p1;
cout << "\n--- Midpoint of Point 1 and Point 2 ---" << endl;
Point mid = p1.midpoint(p2);
cout << "\nPoint 1: "; p1.display();
cout << "Point 2: "; p2.display();
cout << "Copied Point (p3): "; p3.display();
cout << "Midpoint: "; mid.display();
return 0;
}
