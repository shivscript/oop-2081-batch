#include <iostream>
using namespace std;
class Rectangle {
private:
double length;
double width;
public:
Rectangle(double l, double w) : length(l), width(w) {}
double calculateArea() const {
return length * width;
}
void doubleDimensions() {
length *= 2;
width *= 2;
}
};
int main() {
double l,w;
cout<<"Enter the length and width: ";
cin>>l>>w;
Rectangle rect(l, w);
cout << "Original area: " << rect.calculateArea() << endl;
rect.doubleDimensions();
cout << "Area after doubling dimensions: " << rect.calculateArea() << endl;
return 0;
}

