#include<iostream>
using namespace std;
int &element(int array[],int index)
{
    return array[index];
}
int main()
{
    int n[7]={9,8,7,5,3,6,7};
    cout<<"Original value at 5th position: "<<n[4]<<endl;
    element(n,4)=20;
    cout<<"Changed value at 5th position: "<<n[4]<<endl;
    return 0;
}