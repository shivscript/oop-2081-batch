#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class MenuItem {
protected:
    string name;
    double price;
    
public:
    MenuItem(string n, double p) : name(n), price(p) {}
    
    virtual void display() {
        cout << name << " Rs." << fixed << setprecision(2) << price;
    }
    
    double getPrice() { return price; }
    string getName() { return name; }
};

class Appetizer : public MenuItem {
public:
    Appetizer(string n, double p) : MenuItem(n, p) {}
    
    void display() override {
        cout << "?? ";
        MenuItem::display();
    }
};

class MainCourse : public MenuItem {
public:
    MainCourse(string n, double p) : MenuItem(n, p) {}
    
    void display() override {
        cout << "?? ";
        MenuItem::display();
    }
};

class Dessert : public MenuItem {
public:
    Dessert(string n, double p) : MenuItem(n, p) {}
    
    void display() override {
        cout << "?? ";
        MenuItem::display();
    }
};

class Order {
private:
    vector<MenuItem*> items;
    
public:
    void addItem(MenuItem* item) {
        items.push_back(item);
    }
    
    void displayOrder() {
        cout << "\n===== YOUR ORDER =====\n";
        for (MenuItem* item : items) {
            item->display();
            cout << endl;
        }
        cout << "----------------------\n";
        cout << "TOTAL: Rs." << calculateTotal() << endl;
    }
    
    double calculateTotal() {
        double total = 0;
        for (MenuItem* item : items) {
            total += item->getPrice();
        }
        return total;
    }
};

void displayMenu(vector<MenuItem*>& menu) {
    cout << "\n======== MENU ========\n";
    for (int i = 0; i < menu.size(); i++) {
        cout << i + 1 << ". ";
        menu[i]->display();
        cout << endl;
    }
    cout << "0. Finish Order\n";
    cout << "======================\n";
}

int main() {
    vector<MenuItem*> menu = {
        new Appetizer("Fries", 150),
        new Appetizer("Coca_cola", 100),
        new MainCourse("Burger", 170),
        new MainCourse("Momo", 200),
        new Dessert("Chocolate Cake", 60),
        new Dessert("Ice Cream", 80)
    };

    Order myOrder;
    int choice = -1;
    
    cout << "WELCOME TO OUR RESTAURANT!\n";
    
    while (choice != 0) {
        displayMenu(menu);
        cout << "Enter item number to add to order: ";
        cin >> choice;
        
        if (choice > 0 && choice <= menu.size()) {
            myOrder.addItem(menu[choice - 1]);
            cout << "\nAdded ";
            menu[choice - 1]->display();
            cout << " to your order!\n";
        } else if (choice != 0) {
            cout << "Invalid selection! Please try again.\n";
        }
    }
    
    myOrder.displayOrder();
    cout << "\nThank you for your order! Enjoy your meal!\n";
    
    for (MenuItem* item : menu) {
        delete item;
    }
    
    return 0;
}