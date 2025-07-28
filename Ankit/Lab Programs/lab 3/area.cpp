#include <iostream>
#define PI 3.14
using namespace std;

class Area {
public:
    double calculate(double radius) {
        return PI * radius * radius;
    }

    double calculate(double length, double width) {
        return length * width;
    }
};

int main() {
    Area a;
    double circleArea = a.calculate(5.0);
    double rectangleArea = a.calculate(4.0, 6.0);

    cout << "Area of circle: " << circleArea << endl;
    cout << "Area of rectangle: " << rectangleArea << endl;

    return 0;
}
