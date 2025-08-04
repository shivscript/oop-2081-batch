#include <iostream>
using namespace std;
template <typename T>
class Calculator {
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
        if (num2 != 0)
            return num1 / num2;
        else {
            cout << "Error: Division by zero!" << endl;
            return T{}; // Return default value of T
        }
    }
};
int main() {
    // Instantiate Calculator with int
    Calculator<int> calcInt(10, 5);
    cout << "Int Addition: " << calcInt.add() << endl;
    cout << "Int Subtraction: " << calcInt.subtract() << endl;
    cout << "Int Multiplication: " << calcInt.multiply() << endl;
    cout << "Int Division: " << calcInt.divide() << endl;
    cout << endl;
    Calculator<float> calcFloat(7.5f, 2.5f);
    cout << "Float Addition: " << calcFloat.add() << endl;
    cout << "Float Subtraction: " << calcFloat.subtract() << endl;
    cout << "Float Multiplication: " << calcFloat.multiply() << endl;
    cout << "Float Division: " << calcFloat.divide() << endl;
    return 0;
}

