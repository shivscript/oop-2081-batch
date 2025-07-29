#include <iostream>
using namespace std;
class Area {
public:
double calculate(double radius) {
return 3.14159 * radius * radius;
}
double calculate(double length, double width) {
return length * width;
}
};
int main() {
Area a;
double radius = 5.0;
double length = 10.0;
double width = 4.0;
double circleArea = a.calculate(radius);
cout << "Area of Circle with radius " << radius << " is: " << circleArea << endl;
double rectangleArea = a.calculate(length, width);
cout << "Area of Rectangle with length " << length << " and width " << width << " is: " << rectangleArea << endl;
return 0;
}

