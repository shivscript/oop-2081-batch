#include <iostream> 
using namespace std; 
template <typename T> 
T maxValue(T a,T b) {
return (a > b) ? a : b;
}
template <typename T> T maxValue(T a, T b, T c) {
T max = (a > b) ? a : b; return (max > c) ? max : c;
}
int main() {
int i1 = 5, i2 = 10, i3 = 7;
cout << "Max of 2 int: " << maxValue(i1, i2) << endl; 
cout << "Max of 3 int: " << maxValue(i1, i2, i3) << endl; 
float f1 = 3.3, f2 = 7.2, f3 = 5.5;
cout << "Max of 2 float: " << maxValue(f1, f2) << endl; 
cout << "Max of 3 float: " << maxValue(f1, f2, f3) << endl; 
char c1 = 'A', c2 = 'Z', c3 = 'M';
cout << "Max of 2 chars: " << maxValue(c1, c2) << endl; 
cout << "Max of 3 chars: " << maxValue(c1, c2, c3) << endl;
return 0;
}
