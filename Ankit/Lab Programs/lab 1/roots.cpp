#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a, b, c;
    cin >> a >> b >> c;
    double d = b * b - 4 * a * c;
    if (d > 0) {
        double r1 = (-b + sqrt(d)) / (2 * a);
        double r2 = (-b - sqrt(d)) / (2 * a);
        cout << "Roots are real and different: " << r1 << " " << r2 << endl;
    } else if (d == 0) {
        double r = -b / (2 * a);
        cout << "Roots are real and same: " << r << endl;
    } else {
        double real = -b / (2 * a);
        double imag = sqrt(-d) / (2 * a);
        cout << "Roots are complex: " << real << " + " << imag << "i, " << real << " - " << imag << "i" << endl;
    }
    return 0;
}