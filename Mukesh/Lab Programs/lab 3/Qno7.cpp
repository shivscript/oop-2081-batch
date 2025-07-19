#include<iostream>
using namespace std;
class Math {
public:
    int add(int a, int b) 
    {
        return a + b;
    }
    int add(int a, int b, int c) 
    {
        return a + b + c;
    }
};
int main() {
    Math m;
    int sum1 = m.add(5, 10);           
    int sum2 = m.add(3, 6, 9);         
    cout << "Sum of 5 and 10: " << sum1 << endl;
    cout << "Sum of 3, 6 and 9: " << sum2 << endl;
    return 0;
}
