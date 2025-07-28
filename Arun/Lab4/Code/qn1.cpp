/*Write a program to define a class that uses static data members and static member functions to
count and display the number of objects created.*/

#include <iostream>
using namespace std;
class Counter {
private:
static int count;
public:
Counter() {
count++;
cout << "Constructor called. Object number: " << count << endl;
}
static void displayCount() {
cout << "Total number of objects created: " << count << endl;
}
};
int Counter::count = 0;
int main() {
cout << "****Object Creation****" << endl;
Counter obj1;
Counter obj2;
Counter obj3;
Counter obj4;
cout << "*****Display Count Using Static Function****" << endl;
Counter::displayCount(); // Call static function without object
return 0;
}
