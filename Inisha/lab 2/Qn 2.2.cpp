#include<iostream>
using namespace std;

inline float square(float n)
{
 return n*n;
}
int main()
{
    float num1,result;
    cout<<"enter a number for square"<<endl;
    cin>>num1;
    result=square(num1);
    cout<<"The square of the number is:"<<result;
    return 0;
}

