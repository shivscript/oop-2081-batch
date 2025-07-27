#include <iostream>
using namespace std;

template <typename T>
void swapValue(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}
int main() {
    int x = 10, y = 20;
    cout << "Before swapping (int): x = " << x << ", y = " << y << endl;
    swapValue(x, y);
    cout << "After swapping (int): x = " << x << ", y = " << y << endl << endl;
    float f1 = 1.5, f2 = 2.5;
    cout << "Before swapping (float): f1 = " << f1 << ", f2 = " << f2 << endl;
    swapValue(f1, f2);
    cout << "After swapping (float): f1 = " << f1 << ", f2 = " << f2 << endl << endl;
    char c1 = 'A', c2 = 'B';
    cout << "Before swapping (char): c1 = " << c1 << ", c2 = " << c2 << endl;
    swapValue(c1, c2);
    cout << "After swapping (char): c1 = " << c1 << ", c2 = " << c2 << endl;
    return 0;
}

