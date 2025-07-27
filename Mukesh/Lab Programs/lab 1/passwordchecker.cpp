#include <iostream>
#include <string>
using namespace std;

class Password {
    int hasUpper = 0, hasSymbol = 0, hasLower = 0, hasNumber = 0;

public:
    int isUpper(char ch) {
        if (ch >= 65 && ch <= 90) return 1;
        return 0;
    }

    int isLower(char ch) {
        if (ch >= 97 && ch <= 122) return 1;
        return 0;
    }

    int isNumber(char ch) {
        if (ch >= 48 && ch <= 57) return 1;
        return 0;
    }

    int isSymbol(char ch) {
        if ((ch >= 33 && ch <= 47) ||
            (ch >= 58 && ch <= 64) ||
            (ch >= 91 && ch <= 96) ||
            (ch >= 123 && ch <= 126)) {
            return 1;
        }
        return 0;
    }

    int checkPass(string password) {
        if (password.length() <= 8) {
            return 0;
        }

        for (int i = 0; i < password.length(); i++) {
            char ch = password[i];
            if (isUpper(ch)==1) hasUpper = 1;
            else if (isLower(ch)==1) hasLower = 1;
            else if (isNumber(ch)==1) hasNumber = 1;
            else if (isSymbol(ch)==1) hasSymbol = 1;
        }

        if (hasUpper == 1 && hasLower == 1 && hasNumber == 1 && hasSymbol == 1)
            return 1;
        else
            return 0;
    }
};

int main() {
    Password pa;
    string pass;
    cout << "Enter password: ";
    cin >> pass;

    if (pa.checkPass(pass) == 1) {
        cout << "Password is strong." << endl;
    } else {
        cout << "Password is not strong." << endl;
    }

    return 0;
}
