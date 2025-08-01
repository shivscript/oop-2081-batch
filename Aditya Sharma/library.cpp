#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Book {
public:
    int id;
    string title;
    string author;

    void input() {
        cout << "Enter Book ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter Title: ";
        getline(cin, title);
        cout << "Enter Author: ";
        getline(cin, author);
    }

    void display() const {
        cout << "\nID: " << id;
        cout << "\nTitle: " << title;
        cout << "\nAuthor: " << author << "\n";
    }
};

// Function to add a new book
void addBook() {
    Book book;
    book.input();

    ofstream outFile("library.txt", ios::app);
    outFile << book.id << "|" << book.title << "|" << book.author << "\n";
    outFile.close();

    cout << "Book added successfully!\n";
}

// Function to display all books
void displayBooks() {
    ifstream inFile("library.txt");
    string line;
    cout << "\n--- All Books ---\n";
    while (getline(inFile, line)) {
        Book book;
        size_t pos1 = line.find('|');
        size_t pos2 = line.find('|', pos1 + 1);
        book.id = stoi(line.substr(0, pos1));
        book.title = line.substr(pos1 + 1, pos2 - pos1 - 1);
        book.author = line.substr(pos2 + 1);
        book.display();
    }
    inFile.close();
}

// Function to search for a book by ID
void searchBook() {
    int searchID;
    cout << "Enter Book ID to search: ";
    cin >> searchID;

    ifstream inFile("library.txt");
    string line;
    bool found = false;

    while (getline(inFile, line)) {
        size_t pos1 = line.find('|');
        size_t pos2 = line.find('|', pos1 + 1);
        int id = stoi(line.substr(0, pos1));
        string title = line.substr(pos1 + 1, pos2 - pos1 - 1);
        string author = line.substr(pos2 + 1);

        if (id == searchID) {
            cout << "\nBook Found:\n";
            cout << "ID: " << id << "\nTitle: " << title << "\nAuthor: " << author << "\n";
            found = true;
            break;
        }
    }

    if (!found)
        cout << "Book not found.\n";

    inFile.close();
}

// Function to delete a book by ID
void deleteBook() {
    int deleteID;
    cout << "Enter Book ID to delete: ";
    cin >> deleteID;

    ifstream inFile("library.txt");
    ofstream tempFile("temp.txt");

    string line;
    bool deleted = false;

    while (getline(inFile, line)) {
        size_t pos1 = line.find('|');
        int id = stoi(line.substr(0, pos1));

        if (id != deleteID) {
            tempFile << line << "\n";
        } else {
            deleted = true;
        }
    }

    inFile.close();
    tempFile.close();

    remove("library.txt");
    rename("temp.txt", "library.txt");

    if (deleted)
        cout << "Book deleted successfully.\n";
    else
        cout << "Book not found.\n";
}

// Main Menu
int main() {
    int choice;
    do {
        cout << "\n===== Library Management System =====\n";
        cout << "1. Add Book\n";
        cout << "2. Display All Books\n";
        cout << "3. Search Book by ID\n";
        cout << "4. Delete Book by ID\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: searchBook(); break;
            case 4: deleteBook(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
