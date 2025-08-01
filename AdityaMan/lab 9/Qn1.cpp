#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;
struct Item {
int item_ID;
string name;
double price;
string mfd_date;
string company;
};
int main() {
int n;
cout << "Enter number of items: ";
cin >> n;
cin.ignore();
vector<Item> inventory;
for (int i = 0; i < n; ++i) {
Item temp;
cout << "\nEnter details for item " << i + 1 << ":\n";
cout << "Item ID: ";
cin >> temp.item_ID;
cin.ignore();
cout << "Name: ";
getline(cin, temp.name);
cout << "Price: ";
cin >> temp.price;
cin.ignore();
cout << "Manufacturing Date (YYYY-MM-DD): ";
getline(cin, temp.mfd_date);
cout << "Company: ";
5
getline(cin, temp.company);
inventory.push_back(temp);
}
ofstream fout("inventory.txt");
if (!fout) {
cout << "Error opening file for writing.\n";
return 1;
}
for (const auto& item : inventory) {
fout << item.item_ID << "," << item.name << "," << item.price << "," << item.mfd_date << "," << item.company << endl;
}
fout.close();
cout << "\n--- Inventory Records ---\n";
for (const auto& item : inventory) {
cout << "Item ID: " << item.item_ID << endl;
cout << "Name: " << item.name << endl;
cout << "Price: $" << item.price << endl;
cout << "Manufacturing Date: " << item.mfd_date << endl;
cout << "Company: " << item.company << endl;
cout << "--------------------------\n";
}
cout << "Inventory has been saved to inventory.txt\n";
return 0;
}
