#include<iostream>
using namespace std;
int add(int a, int b) {
    return a + b; }
float add(float a, float b) {
    return a + b; }
float add(int a, float b) {
    return a + b; }
int main() {
    int a, b;
    float x, y;
    cout << "Enter 2 integer numbers: ";
    cin >> a >> b;
    cout << "Sum of integers is: " << add(a, b) << endl;
    cout << "Enter 2 float numbers: ";
    cin >> x >> y;
    cout << "Sum of floats is: " << add(x, y) << endl;
    cout << "Enter 1 integer and 1 float number: ";
    cin >> a >> y;
    cout << "Sum of integer and float is: " << add(a, y) << endl;
    return 0;
}
