#include <iostream> 
using namespace std;
enum Day { Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday }; 

int main() {
int a;
Day Today;
cout << "Enter any number between 1 and 7: "; cin >> a;
if (a < 1 || a > 7) {
cout << "Invalid input. Please enter a number between 1 and 7."; return 1;
}
Today = static_cast<Day>(a - 1); switch (Today) {
case Sunday:
cout << "YOOO It's Sunday"; break;
case Monday:
cout << "YOOO It's Monday"; break;
case Tuesday:
cout << "YOOO It's Tuesday"; break;
case Wednesday:
cout << "YODO It's Wednesday"; break;
case Thursday:
cout << "YOOO It's Thursday"; break;
case Friday:
cout << "YOOO It's Friday"; break;
case Saturday:
cout << "YOOO It's Saturday";
 
break;
}
return 0;
}
