
#include <iostream> 
using namespace std;
int& getElement(int arr[], int index) { 
    return arr[index];
}


int main() {
int numbers[5] = {10, 20, 30, 40, 50};
cout << "Before modification: " << numbers[2] << endl;
getElement(numbers, 2) = 100;
cout << "After modification: " << numbers[2] << endl;
return 0;
}
