#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
#include<random>

using namespace std;

class Book{

private: 

    string title;
    int BookID;

public:
    Book(string t, int id) {
        title = t;
        BookID = id;
    }
    string getTitle() const {
        return title;
    }
    int getBookID() const {
        return BookID;
    }
    void display() const {
        cout << "Title: " << title << ", Book ID: " << BookID << endl;
    }
};

class BookSorter {
    public:
    static void sortByTitle(vector<Book> &Books){
        sort(Books.begin(), Books.end(), [](const Book &a, const Book &b){
            return a.getTitle() < b.getTitle();
        });
    }
    static void sortByID(vector<Book> &Books){
        sort(Books.begin(), Books.end(), [](const Book &a, const Book &b){
            return a.getBookID() < b.getBookID();
        });
    }
};
int generateUniqueId(set<int> &existingIds) {
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 999);
    int Id;
    do {
        Id = dis(gen);
    } while(existingIds.count(Id));
    existingIds.insert(Id);
    return Id;
}
int main() {
    vector<Book>books;
    set<int> usedIds;
     int choice;
     while (true){
        cout<<"\n---------Book Sorter Menu--------\n";
        cout<<"1. Add Book\n";
        cout<<"2. Sort by Title\n";
        cout<<"3. Sort by ID\n";
        cout<<"4. Display Books\n";
        cout<<"0. Exit\n";
        cout<<" Enter your Choice:";
        cin>>choice;
        cin.ignore();
        if(choice==1){
            string title,idInput;
            int id;
            cout<<"Enter Book Title:";
            getline(cin, title);

            cout<<"Enter your Book ID OR Leave Blank to auto assign:";
            getline(cin, idInput);

            if (idInput.empty()){
                id=generateUniqueId(usedIds);
                cout<<"Assigned ID: "<<id<<endl;
            }else{
                id=stoi(idInput);
                if(usedIds.count(id)){
                    cout<<"ID already in use. Please enter a different ID.\n";
                    continue;
                }
                usedIds.insert(id);
            }
            books.push_back(Book(title,id));
            cout<<"Book added Succesfully\n";
        }else if (choice==2){
            BookSorter::sortByTitle(books);
            cout<<"Books sorted by Title Succesfully\n";
        }else if (choice==3){
            BookSorter::sortByID(books);
            cout<<"Books sorted by ID Succesfully\n";
        }else if (choice==4){
            if(books.empty()){
                cout<<"No books available to display.\n";
            }  else{
                cout<<"\n Book List:\n";
                for(const Book& b : books) {
                    b.display();
                }
            }
        }else if (choice==0){
            cout<<"terminating program\n";
            break;
        }else{
            cout<<"------Invalid Choice. Please try again-------.\n";
        }
    }
    return 0;
}
    