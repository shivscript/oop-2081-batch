 #include <iostream>
using namespace std;
class Shape {
public:
void display() {
cout << "This is a shape." << endl;
}
};
class Circle : public Shape {
public:
void draw() {
cout << "Drawing a circle." << endl;
}
};
int main() {
Circle c;
c.display(); // Inherited from Shape
c.draw(); // Defined in Circle
return 0;
}

