#include<iostream>
#include<string>
using namespace std;

class Book {
private:
    string title;

public:
    Book(string t) {
        title = t;
    }

    ~Book() {
        cout << "Destructor called" << endl;
    }

    void display() {
        cout << "Title: " << title << endl;
    }
};

int main() {
    Book b("Ankit"); // constructor called
    b.display();
    return 0; // destructor called
} // destructor called