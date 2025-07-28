#incude<iostream>
using namespace std;
int main(){
    double numerator,denominator,result;
    cout<<"Enter numerator:";
    cin>>numerator;
    cout<<"Enter Denominator:";
    cin>>denominator;
    try{
        if(denominator==0){
            throw "Divison by zero is not allowed!";
        }
        result=numerator/denominator;
        cout<<"Result: "<<result<<endl;
    }
    catch(const char* msg){
        cout<<"Erro: "<<msg<<endl;
    }
    return 0;
}