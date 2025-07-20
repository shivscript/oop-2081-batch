#include<iostream>
using namespace std;
float totalprice(float price, int quantity=1)
{
    return price*quantity;
}
int main()
{
    float p=150;
    cout<<"Price with 1 item: "<<totalprice(p)<<endl;;
    cout<<"Price with 9 item: "<<totalprice(p,9)<<endl;
}