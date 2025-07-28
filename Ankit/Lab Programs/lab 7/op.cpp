#include <iostream> 
using namespace std; 
template <typename T> 
class Calculator {
T a, b; 
public:
Calculator(T x, T y) {
a = x;
b = y;
}
T add() { return a + b;
}
T subtract() { return a -b;
}
T multiply(){
 return a * b;
}
T divide() {
return b != 0 ? a / b : 0;
}
};
int main() {
Calculator<int> calcInt(10, 5);
cout << "Int Addition: " << calcInt.add() << endl;
cout << "Int Subtraction: " << calcInt.subtract() << endl;
cout << "Int Multiplication: " << calcInt.multiply() << endl;
cout << "Int Division: " << calcInt.divide() << endl;
Calculator<float> calcFloat(10.5f, 2.5f);
cout << "Float Addition: " << calcFloat.add() << endl;
cout << "Float Subtraction: " << calcFloat.subtract() << endl;
cout << "Float Multiplication: " << calcFloat.multiply() << endl;
cout << "Float Division: " << calcFloat.divide() << endl;
return 0;
}