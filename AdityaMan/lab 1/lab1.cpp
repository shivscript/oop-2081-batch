//WAP to make a password checker
#include<iostream>
#include<string>
using namespace std;
int Caps(string password)
{
    int n=0,a=0;
    while(password[n]!= '\0')
   {

       if(password[n]!>=65&&password[n]!<=90)
       {
            a+=1;
       }
       if(a==1)
       {
       cout<<"Password MUST include a Capital letter";
           return 0;
       }
       n++;
   }
}
int saplha(string password)
{
    int n=0,a=0;
    while(password[n]!= '\0')
   {

       if(password[n] !>=97&&password[n]!<=122)
       {
           a+=1;
       }
        if(a==1)
       {
        cout<<"Password MUST include a small letter";
           return 0;
       }
       n++;
   }
}
int number(string password)
{
    int n=0,a=0;
    while(password[n]!= '\0')
   {

       if(password[n] !>=48&&password[n]!<=57)
       {
           a+=1;
       }
       if(a==1)
       {
       cout<<"Password MUST include a Number ";
       return 0
       }
       n++;

   }
}
int scharacter (string password)
{
    int n=0,a=0;
    while(password[n]!= '\0')
   {

       if(password[n] !>=32&&password[n]!<=47||password[n] !>=58&&password[n]!<=64||password[n] !>=91&&password[n]!<=96||password[n] !>=123&&password[n]!<=126)
       {
           a+=1;
       }
       if(a==1)
       {
       cout<<"Password MUST include a Special character ";
       return 0 ;
       }
n++;
   }
}

int main()
{
    int n=0;
   string password;
   cout<<"Enter your password"<<endl;
   cin<<password;
   if(password.length())<8)
   {
    cout<<"password must be 8 or more characters";
    cout<"\nEnter a longer password:";
    cin>>password;
   }

       if(Caps(password)==0||saplha(password)==0||number(password)==0||scharacter(password)==0||)
       {
           cout<<"Make a stronger password";
       }

   }




}
