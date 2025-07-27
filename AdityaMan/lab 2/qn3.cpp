#include<iostream>
using namespace std;
float calculateTotal(float price,int quantity = 1){
return price*quantity;
}
int main(){
float itemPrice;
cout<<"Enter the item price";
cin>>itemPrice;
cout<<"The price of 1 item is:" << calculateTotal(itemPrice)<<endl;
cout<<"The price of 5 item is:" << calculateTotal(itemPrice,5)<<endl;
return 0;
}
