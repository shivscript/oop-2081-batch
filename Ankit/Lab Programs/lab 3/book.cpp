#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    int year;
    string title;
    string author;

public:
    Book() {
        cout << "Default constructor called " << endl;
    }

    Book(int y, string t, string a) {
        year = y;
        title = t;
        author = a;
    }

    void get() {
        cout << "Details: " << endl;
        cout << "Title    " << "Author    " << "Year" << endl;
        cout << title << "    " << author << "    " << year;
    }
};

int main() {
    Book b1;
    Book b(1999, "alu", "ankit");
    b.get();
    return 0;
}
