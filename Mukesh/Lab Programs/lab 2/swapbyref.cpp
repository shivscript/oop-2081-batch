#include<iostream>
using namespace std;
void swap(int &x, int &y)
{
    int temp=x;
    x=y;
    y=temp;
}
int main()
{
    int a=6, b=4;
    cout<<"Before swaping: a="<<a<<" and b="<<b<<endl;
    swap(a,b);
    cout<<"After swaping: a="<<a<<" and b="<<b<<endl;
    return 0;
}