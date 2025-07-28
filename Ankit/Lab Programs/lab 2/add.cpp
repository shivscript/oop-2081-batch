#include <iostream>
using namespace std;
int add(int a, int b) {
return a + b;
}
double add(double a, double b) { return a + b;
}
int main() {
cout << "Sum of 1 and 2: " << add(1, 2) << endl;
cout << "Sum of 1.5 and 2.5: " << add(1.5, 2.5) << endl;
 return 0;
}
