#include<iostream>
#include<cmath>
using namespace std;

int main() {
    float a, b, c;
    cout << "Enter coefficients a, b, and c for the quadratic equation ax^2 + bx + c = 0:\n";
    cin >> a >> b >> c;

    if (a == 0) {
        cout << "This is not a quadratic equation." << endl;
    } else {
        float d = (b * b) - (4 * a * c);
        float x1, x2;

        if (d == 0) {
            x1 = -b / (2 * a);
            cout << "There exists one real and repeated root: " << x1 << endl;
        } else if (d > 0) {
            x1 = (-b + sqrt(d)) / (2 * a);
            x2 = (-b - sqrt(d)) / (2 * a);
            cout << "There exist two distinct real roots: " << x1 << " and " << x2 << endl;
        } else {
            float realPart = -b / (2 * a);
            float imagPart = sqrt(-d) / (2 * a);
            cout << "There exist two complex roots: ";
            cout << realPart << " + i" << imagPart << " and " << realPart << " - i" << imagPart << endl;
        }
    }
    return 0;
}
