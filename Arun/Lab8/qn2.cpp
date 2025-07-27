/*Write a program to overload a function template maxValue() to find the maximum of two values (for
same type) and three values (for same type). Call it using int, double, and char.*/
#include <iostream>
using namespace std;
template <typename T>
T maxValue(T a, T b) {
    return (a > b) ? a : b;
}
template <typename T>
T maxValue(T a, T b, T c) {
    T max = (a > b) ? a : b;
    return (max > c) ? max : c;
}
int main() {
    int x1, x2, x3;
    cout << "Enter three integers: ";
    cin >> x1 >> x2 >> x3;
    cout << "Max of two integers: " << maxValue(x1, x2) << endl;
    cout << "Max of three integers: " << maxValue(x1, x2, x3) << endl;
    double d1, d2, d3;
    cout << "\nEnter three doubles: ";
    cin >> d1 >> d2 >> d3;
    cout << "Max of two doubles: " << maxValue(d1, d2) << endl;
    cout << "Max of three doubles: " << maxValue(d1, d2, d3) << endl;
    char c1, c2, c3;
    cout << "\nEnter three characters: ";
    cin >> c1 >> c2 >> c3;
    cout << "Max of two characters: " << maxValue(c1, c2) << endl;
    cout << "Max of three characters: " << maxValue(c1, c2, c3) << endl;
    return 0;
}
