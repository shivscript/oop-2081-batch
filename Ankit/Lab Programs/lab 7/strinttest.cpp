#include<iostream>
#include <string>
using namespace std;
template <typename T>
class Base {
protected:
    T data1;
public:
Base(T val) { data1 = val;
}
void displayData1() {
cout << "Data1: " << data1 << endl;
}
};
template <typename T>
class Derived : public Base<T> { T data2;
public:
Derived(T val1, T val2) : Base<T>(val1) { data2 = val2;
}
void displayBoth() { this->displayData1();
cout << "Data2: " << data2 << endl;
}
};

int main() {
    Derived<int> objInt(10, 20); cout << "Int Type:" << endl;
    objInt.displayBoth();
    Derived<string> objStr("Ankit", "Belbase"); cout << "\nString Type:" << endl;
    objStr.displayBoth();
    return 0;
}
