/*Write a program for transaction processing that write and read
object randomly to and from a random access file so that user can add, update, delete and display the
account information (accountnumber, lastname, firstname, totalbalance).*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

const string FILE_NAME = "accounts.dat";
struct Account {
    int accountNumber;
    char lastName[20];
    char firstName[25];
    double totalBalance;
};
int getPosition(int accountNumber) {
    return (accountNumber - 1) * sizeof(Account);
}
void addAccount() {
    fstream file(FILE_NAME, ios::in | ios::out | ios::binary);
    Account acc;
    cout << "Enter Account Number (1-100): ";
    cin >> acc.accountNumber;
    if (acc.accountNumber < 1 || acc.accountNumber > 100) {
        cout << "Invalid account number.\n";
        return;
    }
    cout << "Enter Last Name: ";
    cin >> acc.lastName;
    cout << "Enter First Name: ";
    cin >> acc.firstName;
    cout << "Enter Total Balance: ";
    cin >> acc.totalBalance;
    file.seekp(getPosition(acc.accountNumber), ios::beg);
    file.write(reinterpret_cast<char*>(&acc), sizeof(Account));
    cout << "Account added successfully.\n";
    file.close();
}
//Compiled By Arun Sauden
void displayAccounts() {
    ifstream file(FILE_NAME, ios::in | ios::binary);
    Account acc;
    cout << "\nAll Accounts:\n";
    cout << left << setw(15) << "Account#" << setw(15) << "Last Name"
         << setw(15) << "First Name" << setw(15) << "Balance\n";
    cout << "---------------------------------------------------------------\n";

    while (file.read(reinterpret_cast<char*>(&acc), sizeof(Account))) {
        if (acc.accountNumber != 0) {
            cout << left << setw(15) << acc.accountNumber
                 << setw(15) << acc.lastName
                 << setw(15) << acc.firstName
                 << fixed << setprecision(2)
                 << setw(15) << acc.totalBalance << endl;
        }
    }
    file.close();
}
void updateAccount() {
    fstream file(FILE_NAME, ios::in | ios::out | ios::binary);
    int accNum;
    cout << "Enter Account Number to Update: ";
    cin >> accNum;
    Account acc;
    file.seekg(getPosition(accNum), ios::beg);
    file.read(reinterpret_cast<char*>(&acc), sizeof(Account));
    if (acc.accountNumber == 0) {
        cout << "Account not found.\n";
    } else {
        cout << "Current Balance: " << acc.totalBalance << endl;
        cout << "Enter new balance: ";
        cin >> acc.totalBalance;

        file.seekp(getPosition(accNum), ios::beg);
        file.write(reinterpret_cast<char*>(&acc), sizeof(Account));
        cout << "Account updated successfully.\n";
    }
    file.close();
}
void deleteAccount() {
    fstream file(FILE_NAME, ios::in | ios::out | ios::binary);
    int accNum;
    cout << "Enter Account Number to Delete: ";
    cin >> accNum;
    Account empty = {0, "", "", 0.0}; // empty record
    file.seekp(getPosition(accNum), ios::beg);
    file.write(reinterpret_cast<char*>(&empty), sizeof(Account));
    cout << "Account deleted successfully.\n";
    file.close();
}
void initializeFile() {
    fstream file(FILE_NAME, ios::in | ios::binary);
    if (!file) {
        ofstream newFile(FILE_NAME, ios::out | ios::binary);
        Account blank = {0, "", "", 0.0};
        for (int i = 0; i < 100; ++i) {
            newFile.write(reinterpret_cast<char*>(&blank), sizeof(Account));
        }
        newFile.close();
        cout << "Initialized empty data file.\n";
    } else {
        file.close();
    }
}
void menu() {
    int choice;
    do {
        cout << "\n==== Account Management ====\n";
        cout << "1. Add Account\n";
        cout << "2. Update Account\n";
        cout << "3. Delete Account\n";
        cout << "4. Display All Accounts\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addAccount(); break;
            case 2: updateAccount(); break;
            case 3: deleteAccount(); break;
            case 4: displayAccounts(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid option!\n";
        }
    } while (choice != 5);
}
int main() {
    initializeFile();
    menu();
    return 0;
}
