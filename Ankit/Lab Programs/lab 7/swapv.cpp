#include <iostream> 
using namespace std; 
template <typename T>
void swapValues(T& a, T& b) { T temp = a;
a = b;
b = temp;
}
int main() {
int x = 10, y = 20; swapValues(x, y);
cout << "Swapped int: x = " << x << ", y = " << y << endl;


float p = 1.5, q = 2.5; swapValues(p, q);
cout << "Swapped float: p = " << p << ", q = " << q << endl;


char c1 = 'A', c2 = 'B'; swapValues(c1, c2);
cout << "Swapped char: c1 = " << c1 << ", c2 = " << c2 << endl;
return 0;
}
