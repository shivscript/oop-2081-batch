#include <iostream>
using namespace std;

class Count {
    int value;
public:
    Count(int v = 0) : value(v) {}

    // Prefix ++
    Count& operator++() {
        ++value;
        return *this;
    }

    // Postfix ++
    Count operator++(int) {
        Count temp = *this;
        value++;
        return temp;
    }

    void display() {
        cout << "Value: " << value << endl;
    }
};

int main() {
    Count c(5);

    ++c;
    c.display();

    c++;
    c.display();

    return 0;
}
