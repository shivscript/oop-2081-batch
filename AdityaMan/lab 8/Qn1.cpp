#include <iostream>
using namespace std;
int main() {
double numerator, denominator, result;
cout << "\nEnter numerator: ";
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
cout<<"Do you wish to continue? (y/n)"<<endl;
char ch;
cin>>ch;
if(ch=='y')
main();
}
return 0;
}