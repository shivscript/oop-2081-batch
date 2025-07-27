#include <iostream>
using namespace std;
void swapNumbers(int &a, int &b) {
int temp = a;
a = b;
b = temp;
}
int main() {
int x, y;
cout<<"Enter 2 numbers";
cin>>x>>y;
cout << "Before swap: x = " << x << ", y = " << y << endl;
swapNumbers(x, y);
cout << "After swap: x = " << x << ", y = " << y << endl;
return 0;
}
