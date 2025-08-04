#include<iostream>
#include<string>
using namespace std;
//special characters
int scharacter(string password,int len)
{
int temp1=0;
while(len>=0)
{
if(password[len]>=34&&password[len]<=47||password[len]>=58&&password[len]<=64||password[len]>=123&&password[len]<=126)
{
temp1++;
}
len--;
}
return temp1;
}
//caps letter
int caps(string password, int len)
{
int temp2=0;
while(len>=0)
{
if(password[len]>=65&&password[len]<=90)
{
temp2++;
}
len--;
}
return temp2;
}
//small letters
int small(string password,int len)
{
int temp3=0;
while(len>=0)
{
if(password[len]>=97&&password[len]<=122)
{
temp3++;
}
len--;
}
return temp3;
}
//numbers
int num(string password, int len)
{
int temp4=0;
while(len>=0)
{
if(password[len]>=48&&password[len]<=57)
{
temp4++;
}
len--;
}
return temp4;
}
int main()
{
int len,a,b,c,d;
string password;
cout<<"enter a strong password"<<endl;
cin>>password;
len=password.length();
a=scharacter(password,len);
b=caps(password, len);
c=small(password, len);
d=num(password,len);
if(a>=1&&b>=1&&c>=1&&d>=1)
{
cout<<"**the password is strong**";
}
else{
cout<<"**the password is weak**"<<endl<<"CHOOSE A STRONGER PASSWORD";
}
return 0;
}
