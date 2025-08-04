#include <iostream>
using namespace std;
int main() {
int angle1, angle2, angle3;
cout << "Enter three angles of the triangle: ";
cin >> angle1 >> angle2 >> angle3;
int sum = angle1 + angle2 + angle3;
// Check if the angles form a valid triangle
if (sum != 180 || angle1 <= 0 || angle2 <= 0 || angle3 <= 0) {
cout << "Invalid triangle. Angles do not sum up to 180 degrees." << endl;
}
else if (angle1 == 90 || angle2 == 90 || angle3 == 90) {
cout << "The triangle is a right-angled triangle." << endl;
}
else if (angle1 > 90 || angle2 > 90 || angle3 > 90) {
cout << "The triangle is an obtuse-angled triangle." << endl;
}
else {
cout << "The triangle is an acute-angled triangle." << endl;
}
return 0;
}
