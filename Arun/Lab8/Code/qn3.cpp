/*Create a class template Calculator<T> that performs addition, subtraction, multiplication, and
division of two data members of type T. Instantiate it with int and float.*/
#include <iostream>
using namespace std;
template <typename T>
class Calculator {
private:
    T num1, num2;
public:
    Calculator(T a, T b) : num1(a), num2(b) {}
    T add() {
        return num1 + num2;
    }
    T subtract() {
        return num1 - num2;
    }
    T multiply() {
        return num1 * num2;
    }
    T divide() {
        if (num2 == 0) {
            cout << "Error: Division by zero!" << endl;
            return 0;
        }
        return num1 / num2;
    }
};
int main() {
    int a, b;
    cout << "Enter two integers: ";
    cin >> a >> b;
    Calculator<int> intCalc(a, b);
    cout << "\nInteger Operations:\n";
    cout << "Addition: " << intCalc.add() << endl;
    cout << "Subtraction: " << intCalc.subtract() << endl;
    cout << "Multiplication: " << intCalc.multiply() << endl;
    cout << "Division: " << intCalc.divide() << endl;
    float x, y;
    cout << "\nEnter two float numbers: ";
    cin >> x >> y;
    Calculator<float> floatCalc(x, y);
    cout << "\nFloat Operations:\n";
    cout << "Addition: " << floatCalc.add() << endl;
    cout << "Subtraction: " << floatCalc.subtract() << endl;
    cout << "Multiplication: " << floatCalc.multiply() << endl;
    cout << "Division: " << floatCalc.divide() << endl;
    return 0;
}
