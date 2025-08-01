#include <iostream>
using namespace std;
class Counter {
private:
    int count;
public:
    Counter(int c = 0) : count(c) {}
    void display() {
        cout << "Count: " << count << endl;
    }
    Counter& operator++() {
        ++count;
        return *this;
    }
    Counter operator++(int) {
        Counter temp = *this;
        count++;
        return temp;
    }
};
int main() {
    Counter c1(5);
    cout << "Original: ";
    c1.display();

    ++c1;
    cout << "After prefix ++: ";
    c1.display();
    c1++;
    cout << "After postfix ++: ";
    c1.display();
    return 0;
}
