#include<iostream>
using namespace std;
inline int square(int n){
return n*n;
}
int main(){
int num1,num2;
cout<<"Enter numbers you want sum of";
cin>>num1>>num2;
cout<<"The square of "<<num1<<" is"<<square(num1)<<endl;
cout<<"The square of "<<num2<<" is "<<square(num2)<<endl;
return 0;
}
