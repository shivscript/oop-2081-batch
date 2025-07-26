#include<iostream>
using namespace std;
class Area {
public:
    double calculate(double radius) {
        return 3.14 * radius * radius;
    }
    double calculate(double length, double width) {
        return length * width;
    }
};
int main() {
    Area a;
    double circleArea = a.calculate(5.0);      
    double rectangleArea = a.calculate(4.0, 6.0); 
    cout << "Area of circle with radius 5: " << circleArea << endl;
    cout << "Area of rectangle with length 4 and width 6: " << rectangleArea << endl;
    return 0;
}
