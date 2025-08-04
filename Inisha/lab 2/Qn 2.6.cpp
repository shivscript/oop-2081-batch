#include<iostream>
using namespace std;
int main()
{
    int arr[40],n;
    int *ptr=arr;
    cout<<"enter the number of elements of array";
    cin>>n;
    for(int i=0;i<n;i++)
    {
       cout<<"Enter element "<<i+1<<endl;
       cin>>*(ptr+i);

    }
    //for square
    cout<<"the square of the arrays are"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<(*(ptr+i))*(*(ptr+i))<<endl;
    }
    return 0;
}

