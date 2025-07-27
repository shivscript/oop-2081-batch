#include <iostream>
using namespace std;
int main() {
int arr[5];
int* ptr = arr; 
cout << "Enter 5 integers:\n";
for (int i = 0; i < 5; i++) {
cin >> *(ptr + i); 
}
cout << "\nSquares of the entered integers:\n";
for (int i = 0; i < 5; i++) {
cout << *(ptr + i) << "^2 = " << (*(ptr + i)) * (*(ptr + i)) << endl;
}
return 0;
}
