#include<iostream>
using namespace std;
int main() {
float angle1, angle2, angle3;
cout<<"Enter 3 angles for a triangle";
cin>>angle1>>angle2>>angle3;
if(angle1+angle2+angle3 != 180)
cout<<"Invalid triangle";
else {
if(angle1>90||angle2>90||angle3>90)
cout<<"It is an obtuse triangle";
else if(angle1<90 && angle2<90 && angle3<90)
cout<<"It is an acute triangle";
7
else if (angle1==90||angle2==90||angle3==90)
cout<<"It is a right angled triangle";
else
cout<<"not a triangle";
}
}