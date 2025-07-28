#include<iostream>
#include<string>
using namespace std;

class Rectangle {
private:
    double length;
    double width;

public:
    Rectangle(int l, int w) {
        length = l;
        width = w;
    }

    double calculateArea() {
        return length * width;
    }

    double doubleDimensions(Rectangle &rect) {
        return length = 2 * rect.length, width = 2 * rect.width;
    }
};

int main() {
    double n;
    Rectangle rect(1, 2);
    cout << "Original Area: " << rect.calculateArea() << endl;

    rect.doubleDimensions(rect);
    cout << "Doubled parameter Area: " << rect.calculateArea() << endl;

    return 0;
}
