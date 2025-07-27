#include<iostream>
using namespace std;
class Animal {
    public: 
    void speak1() {
        cout<<"Animal make sound like: ";
    }
};
class Dog : public Animal {
    public:
    void speak(){
        speak1();
        cout<<"Dog barks: "<<endl;
    }
};
class Cat : public Animal {
    public:
    void speak(){
        speak1();
        cout<<"Cat meows. "<<endl;
    }
};
int main()
{
    Dog D;
    Cat C;
    D.speak();
    C.speak();
    return 0;
}
