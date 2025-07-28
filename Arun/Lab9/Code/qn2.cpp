#include<iostream>
#include<string>
using namespace std;
int main(){
int choice;
cout<<"Enter a number(1 for int,2 for char, 3 for string)";
cin>>choice;
try{
if(choice==1){
    throw 46;
} else if(choice==2){
throw 'A';
}
else if(choice==3){
    throw string("Arun as String");
}
    else{
        cout<<"No exception thrown.Invalid choice."<<endl;
    }
}
catch(int e){
cout<<"Caught integer exception:"<<e<<endl;
}
catch(char e){
cout<<"Caught character exception:"<<e<<endl;
}
catch(string e){
cout<<"Caught string exception:"<<e<<endl;
}
catch(...){
cout<<"Caught unknown exception"<<endl;
}
return 0;
}
