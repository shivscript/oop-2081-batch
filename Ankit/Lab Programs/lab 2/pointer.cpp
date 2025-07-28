#include <iostream> 
using namespace std;
 
int main() { 
    int arr[5];
    int *ptr = arr;
    cout << "Enter 5 integers:\n"; 
    for (int i = 0; i < 5; i++) {
        cin >> *(ptr + i);
    }
    cout << "Squares of the entered numbers:\n"; 
    for (int i = 0; i < 5; i++) {
    int val = *(ptr + i);
    cout << val << "^2 = " << val * val << endl;
    }
    return 0;
}
