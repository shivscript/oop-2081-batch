#include<iostream>
using namespace std;
int main()
{
    int a,b,c;
    cout<<"Enter 1st angle: ";
    cin>>a;
    cout<<"Enter 2nd angle: ";
    cin>>b;
    cout<<"Enter 3rd angle: ";
    cin>>c;
    if(a+b+c==180)
    {
        if(a==90 || b==90 || c==90)
        {
            cout<<"Figure is right angled triangle. ";
            goto end;
        }
        else if(a>90 || b>90 || c>90)
        {
            cout<<"Figure is obtuse angled triangle. ";
            goto end;
        }
        else
        {
            cout<<"Figure is acute angled triangle. ";
            goto end;
        }
    }
    else
    {
        cout<<"Given angles don't form a triangle.";
    }
    end:
}