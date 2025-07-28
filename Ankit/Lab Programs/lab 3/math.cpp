#include <iostream>
using namespace std;

class Math {
public:
    int add(int a, int b) {
        return a + b;
    }

    int add(int a, int b, int c) {
        return a + b + c;
    }
};

int main() {
    Math m;
    cout << "Sum of 2 and 3: " << m.add(2, 3) << endl;
    cout << "Sum of 1, 2 and 3: " << m.add(1, 2, 3) << endl;
    return 0;
}
