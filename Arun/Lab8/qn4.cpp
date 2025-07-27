/*Define a class template Base<T> with a protected data member and a member function to display it.
Derive a class Derived<T> from it, add another data member, and display both data members. Use string
and int types to test.*/
#include <iostream>
#include <string>
using namespace std;
template <typename T>
class Base {
protected:
    T baseData;
public:
    Base(T val) : baseData(val) {}
    void display() {
        cout << "Base data: " << baseData << endl;
    }
};
template <typename T>
class Derived : public Base<T> {
private:
    T derivedData;
public:
    Derived(T baseVal, T derivedVal) : Base<T>(baseVal), derivedData(derivedVal) {}
    void display() {
        cout << "Base data: " << this->baseData << endl;
        cout << "Derived data: " << derivedData << endl;
    }
};
int main() {
    cout << "Testing with int:\n";
    Derived<int> intObj(10, 20);
    intObj.display();
    cout << "\nTesting with string:\n";
    Derived<string> strObj("BaseString", "DerivedString");
    strObj.display();
    return 0;
}
