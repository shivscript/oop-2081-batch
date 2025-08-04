#include<iostream>
using namespace std;

float calculate(float price, int quantity=1)
{
    float total;
    total=price*quantity;
    return total;
}

int main()
{
    float price, result,result1;
    int quantity;
    cout<<"Enter the price ";
    cin>>price;

    cout<<"Enter the quantity";
    cin>>quantity;

    result1=calculate(price);
    cout<<"the price is(for one quantity)"<<result1<<endl;
    result=calculate(price,quantity);
    cout<<"the price is(for given quantity)"<<result;
    return 0;
}


