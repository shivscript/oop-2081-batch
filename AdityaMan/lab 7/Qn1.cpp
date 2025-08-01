#include <iostream>
using namespace std;
template <typename T>
void swapValues(T &a, T &b) {
T temp = a;
a = b;
b = temp;
}
int main() {
int x = 10, y = 20;
cout << "Before swapping (int): x = " << x << ", y = " << y << endl;
swapValues(x, y);
cout << "After swapping (int): x = " << x << ", y = " << y << endl;
float f1 = 1.5, f2 = 3.7;
cout << "\nBefore swapping (float): f1 = " << f1 << ", f2 = " << f2 << endl;
swapValues(f1, f2);
cout << "After swapping (float): f1 = " << f1 << ", f2 = " << f2 << endl;
char c1 = 'A', c2 = 'B';
cout << "\nBefore swapping (char): c1 = " << c1 << ", c2 = " << c2 << endl;
swapValues(c1, c2);
cout << "After swapping (char): c1 = " << c1 << ", c2 = " << c2 << endl;
return 0;
}