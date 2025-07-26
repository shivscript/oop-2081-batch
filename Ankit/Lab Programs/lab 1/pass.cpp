#include <iostream>
#include <string>
using namespace std;

bool isUpper(char ch) {
    return ch >= 'A' && ch <= 'Z';
}

bool isLower(char ch) {
    return ch >= 'a' && ch <= 'z';
}

bool isDigit(char ch) {
    return ch >= '0' && ch <= '9';
}

bool isStrongPassword(const string& pwd) {
    if (pwd.length() < 8) return false;
    bool hasUpper = false, hasLower = false, hasDigit = false, hasSpecial = false;
    for (char ch : pwd) {
        if (isUpper(ch)) hasUpper = true;
        else if (isLower(ch)) hasLower = true;
        else if (isDigit(ch)) hasDigit = true;
        else hasSpecial = true;
    }
    return hasUpper && hasLower && hasDigit && hasSpecial;
}

int main() {
    string password;
    cout << "Enter password: ";
    getline(cin, password);
    if (isStrongPassword(password))
        cout << "Strong password\n";
    else
        cout << "Weak password\n";
    return 0;
}