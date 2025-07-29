#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a, b, c;
    cout << "Enter coefficients a, b and c: ";
    cin >> a >> b >> c;

    // Calculate the discriminant
    double discriminant = b * b - 4 * a * c;

    cout << "Quadratic Equation: " << a << "x^2 + " << b << "x + " << c << " = 0\n";

    // Check the nature of the roots
    if (discriminant > 0) {
        double root1 = (-b + sqrt(discriminant)) / (2 * a);
        double root2 = (-b - sqrt(discriminant)) / (2 * a);
        cout << "Roots are real and distinct.\n";
        cout << "Root 1 = " << root1 << "\n";
        cout << "Root 2 = " << root2 << "\n";
    }
    else if (discriminant == 0) {
        double root = -b / (2 * a);
        cout << "Roots are real and equal.\n";
        cout << "Root = " << root << "\n";
    }
    else {
        double realPart = -b / (2 * a);
        double imagPart = sqrt(-discriminant) / (2 * a);
        cout << "Roots are complex and imaginary.\n";
        cout << "Root 1 = " << realPart << " + " << imagPart << "i\n";
        cout << "Root 2 = " << realPart << " - " << imagPart << "i\n";
    }

    return 0;
}
