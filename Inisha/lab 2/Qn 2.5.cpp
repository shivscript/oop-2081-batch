#include<iostream>
using namespace std;
int& modifyElement(int arr[],int index)
{
    return arr[index];
}
int main()
{
    int arr[100],n,num,result;
    cout<<"enter the number of elements of array";
    cin>>n;
    for(int i=0;i<n;i++)
    {
       cout<<"Enter element "<<i+1<<endl;
       cin>>arr[i];

    }
    int index1;
    cout<<"enter the element you want to modify";
    cin>>index1;
    cout<<"enter the number you want to replace with";
    cin>>num;
    result=modifyElement(arr,index1)=num;
    cout<<"the element after modification"<<" "<<"arr["<<index1<<"]"<<result<<endl;
    return 0;
    }

