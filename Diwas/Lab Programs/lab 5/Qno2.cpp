#include <iostream>
using namespace std;
class inc {
    float var1;
public:
    inc(int a)
    {
        var1=a;
    }
    inc&operator++() {
        ++var1;
        return *this;
    }
    inc operator++(int) {
        inc temp = *this;
        var1++;
        return temp;
    }
    void display(){
        cout << "Value is: "<<var1<<endl;
    }
};
int main() {
    inc c1(5);
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
