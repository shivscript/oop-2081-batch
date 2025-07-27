#include<iostream>
using namespace std;
int main()
{
    int array[4];
    int *p=array;
    cout<<"Enter 4 numbers: "<<endl;
    for(int i=0;i<4;i++)
    {
        cin>>*(p+i);
    }
    cout<<"Squares are: "<<endl;
    for(int i=0;i<4;i++)
    {
        cout<<*(p+i)<<"*"<<*(p+i)<<"="<<(*(p+i))*(*(p+i))<<endl;
    }
    return 0;
}