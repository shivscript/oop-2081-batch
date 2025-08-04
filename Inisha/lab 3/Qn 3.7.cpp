#include <iostream>
using namespace std;
class Math {
public:
int add(int a, int b) {
return a + b;
}
int add(int a, int b, int c) {
return a + b + c;
}
};
int main() {
Math m;
int x, y, z;
cout << "Enter two integers: ";
cin >> x >> y;
cout << "Sum of two integers: " << m.add(x, y) << endl;
cout << "Enter three integers: ";

cin >> x >> y >> z;
cout << "Sum of three integers: " << m.add(x, y, z) << endl;
return 0;
}

