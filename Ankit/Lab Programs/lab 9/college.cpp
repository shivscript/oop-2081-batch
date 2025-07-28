#include <iostream>
#include <fstream>
using namespace std;

class Book {
private:
    int bookID;
    char bookName[50];
    int numBooks;
    char purchaseDate[15];

public:
    void input() {
        cout << "Enter Book ID: ";
        cin >> bookID;
        cin.ignore();
        cout << "Enter Book Name: ";
        cin.getline(bookName, 50);
        cout << "Enter Number of Books: ";
        cin >> numBooks;
        cin.ignore();
        cout << "Enter Purchase Date (YYYY-MM-DD): ";
        cin.getline(purchaseDate, 15);
    }

    void display() const {
        cout << "Book ID: " << bookID << "\n"
             << "Book Name: " << bookName << "\n"
             << "Number of Books: " << numBooks << "\n"
             << "Purchase Date: " << purchaseDate << "\n"
             << "-----------------------------\n";
    }

    void writeToFile(ofstream& fout) {
        fout.write(reinterpret_cast<char*>(this), sizeof(*this));
    }

    void readFromFile(ifstream& fin) {
        fin.read(reinterpret_cast<char*>(this), sizeof(*this));
    }
};

int main() {
    int n;
    cout << "Enter number of books to add: ";
    cin >> n;
    cin.ignore();

    ofstream fout("library.dat", ios::binary | ios::app);
    if (!fout) {
        cerr << "Error opening file for writing!\n";
        return 1;
    }

    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for book " << (i + 1) << ":\n";
        Book b;
        b.input();
        b.writeToFile(fout);
    }
    fout.close();

    ifstream fin("library.dat", ios::binary);
    if (!fin) {
        cerr << "Error opening file for reading!\n";
        return 1;
    }

    cout << "\n---- Library Book Records ----\n";
    Book b;
    while (fin.read(reinterpret_cast<char*>(&b), sizeof(b))) {
        b.display();
    }
    fin.close();
    return 0;
}


