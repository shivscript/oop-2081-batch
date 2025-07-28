#include <iostream> 
using namespace std;

class Person { public:
virtual void show() {
cout << "Person's show method" << endl;
}
};

class Employee { public:
virtual void show() {
cout << "Employee's show method" << endl;
}
};

class Manager : public Person, public Employee { public:
void show() override {
cout << "Manager's show method" << endl;
}
};
int main() {
Manager m;
Person* p = &m;
Employee* e = &m;
p->show();
e->show(); 
return 0;
}

