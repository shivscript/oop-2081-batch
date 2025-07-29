/*Write a program to create a class LandMeasure with units Ropani, Ana, Paisa, and Dam. Define a
function to add two objects, applying proper unit conversion (16 Ana = 1 Ropani, etc.).*/
#include <iostream>
using namespace std;
class LandMeasure {
private:
int ropani, ana, paisa, dam;
public:
LandMeasure(int r = 0, int a = 0, int p = 0, int d = 0) {
ropani = r;
ana = a;
paisa = p;
dam = d;
}
void input() {
cout << "Enter Ropani: ";
cin >> ropani;
cout << "Enter Ana: ";
cin >> ana;
cout << "Enter Paisa: ";
cin >> paisa;
cout << "Enter Dam: ";
cin >> dam;
}
LandMeasure add(const LandMeasure& lm) const {
int d = dam + lm.dam;
int p = paisa + lm.paisa + (d / 4); d %= 4;
int a = ana + lm.ana + (p / 4); p %= 4;
int r = ropani + lm.ropani + (a / 16); a %= 16;
return LandMeasure(r, a, p, d);
}
void display() const {
cout << "Total Land = " << ropani << " Ropani, "
<< ana << " Ana, "
<< paisa << " Paisa, "
<< dam << " Dam" << endl;
}
};
int main() {
LandMeasure land1, land2;
cout << " Enter Land 1 Details :" << endl;
land1.input();
cout << "\nEnter Land 2 Details: " << endl;
land2.input();
LandMeasure total = land1.add(land2);
cout << "\nCombined Land Measurement: " << endl;
total.display();
return 0;
}
