#include <iostream>
using namespace std;
int main() {
double numerator, denominator, result;
cout << "Enter numerator: ";
cin >> numerator;
cout << "Enter denominator: ";
cin >> denominator;
try {
if (denominator == 0) {
throw "Division by zero is not allowed!";
}
result = numerator / denominator;
cout << "Result: " << result << endl;
}
catch (const char* msg) {
cout << "Error: " << msg << endl;
}
return 0;
}
