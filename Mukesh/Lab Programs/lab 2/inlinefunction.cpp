#include <iostream>
using namespace std;
inline int sq (int n)
{
    return n * n;
}
int main() 
{
    int num1 = 5, num2 = 9;
    cout<< "Square of " << num1 << " is: " << sq (num1) << endl;
    cout<< "Square of " << num2 << " is: " << sq (num2) << endl;
    return 0;
}