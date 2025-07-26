#include<iostream>
using namespace std;
int add(int a, int b)
{
    return a+b;
}
float add(float a, float b)
{
    return a+b;
}
float add(int a, float b)
{
    return a+b;
}
int main()
{
    int i1=5, i2=6;
    float f1=4.526, f2=6.265;
    cout<<"Intger sum: "<<add(i1,i2)<<endl;
    cout<<"Float sum: "<<add(f1,f2)<<endl;;
    cout<<"Mixed sum: "<<add(i1,f1)<<endl;
    return 0;
}