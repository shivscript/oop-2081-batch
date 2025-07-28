#include <iostream> 
using namespace std;
double totalPrice(double price, int quantity = 1) {
     return price * quantity;
}
int main() {
cout << "Total price (1 item at $10.5): $" << totalPrice(10.5) << endl;
cout << "Total price (3 items at $10.5 each): $" << totalPrice(10.5, 3) << endl; 
return 0;
}
