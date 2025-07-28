#include <iostream>
using namespace std;
int main() {
int choice;
cout << "Enter a number (1 to throw double, 2 to throw bool, any other to throw unknown): ";
cin >> choice;
try {
if (choice == 1) {
throw 3.14;
}
else if (choice == 2) {
throw true;
}
else {
throw nullptr;
}
}
catch (double a) {
cout << "Caught double exception: " << a << endl;
}
catch (bool a) {
cout << "Caught boolean exception: " << (a? "true" : "false") << endl;
}
catch (...) {
cout << "Caught unknown exception using catch-all handler" << endl;
}
return 0;
}
