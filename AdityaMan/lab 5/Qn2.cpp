#include<iostream>
using namespace std;
class Counter {
    int count;
public:
    Counter(int c = 0) : count(c) {}
    Counter operator++() {
        ++count;
        return *this;
    }
    Counter operator++(int) {
        Counter temp = *this;
        count++;
        return temp;
    }
    void display() {
        cout << "Count: " << count << endl;
    }
};
int main() {
    Counter c1(5);
    cout << "Initial ";
    c1.display();
    ++c1;
    cout << "After Prefix ++ ";
    c1.display();
    c1++;
    cout << "After Postfix ++ ";
    c1.display();
    return 0;
}
