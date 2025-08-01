#include <iostream>
using namespace std;
int main() {
try {
int choice;
cout << "Enter 1 for int, 2 for double, 3 for char, 4 for bool: ";
cin >> choice;
if (choice == 1)
throw 100;
else if (choice == 2)
throw 3.14;
else if (choice == 3)
throw 'Z';
else if (choice == 4)
throw true;
else
throw "Unknown type";
}
catch (int e) {
cout << " Int exception: " << e << endl;
}
catch (...) {
cout << "Here is an exception of unknown or unexpected type!" << endl;
}
cout << "Now the program continues." << endl;
return 0;
}