#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cout << "Enter three angles of triangle: ";
    cin >> a >> b >> c;
    if (a + b + c == 180 && a > 0 && b > 0 && c > 0) {
        if (a == 90 || b == 90 || c == 90)
            cout << "Right-angled triangle\n";
        else if (a < 90 && b < 90 && c < 90)
            cout << "Acute-angled triangle\n";
        else
            cout << "Obtuse-angled triangle\n";
    } else {
        cout << "Not a valid triangle\n";
    }
    return 0;
}