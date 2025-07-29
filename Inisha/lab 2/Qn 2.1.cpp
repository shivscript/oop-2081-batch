#include<iostream>
#include<cmath>
using namespace std;

int add(int a,int b)
{
  return a+b;
}
float add(float c, float d)
{
    return c+d;
}
float add(float e, int f)
{
    return e+f;
}

int main()
{
    float num1, num2,result1, result2, result3;

    cout<<"enter any two integer numbers"<<endl;
    cin>>num1>>num2;
    result1=add(num1,num2);
    cout<<"the sum is:"<<result1<<endl;

    cout<<"enter any two float numbers"<<endl;
    cin>>num1>>num2;
    result2=add(num1,num2);
    cout<<"the sum is:"<<result2;

    cout<<"enter any one float and one interger number"<<endl;
    cin>>num1>>num2;
    result3=add(num1,num2);
    cout<<"the sum is:"<<result3;

    return 0;
}


