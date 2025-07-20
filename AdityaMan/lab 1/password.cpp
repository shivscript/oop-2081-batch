#include <iostream>
#include <string>
using namespace std;

int Uppercase(string password) {
    for (int i = 0; i < password.length(); i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            return 1;
        }
    }
    cout << "Password MUST include at least one Capital letter.\n";
    return 0;
}

int Lowercase(string password) {
    for (int i = 0; i < password.length(); i++) {
        if (password[i] >= 'a' && password[i] <= 'z') {
            return 1;
        }
    }
    cout << "Password MUST include at least one Small letter.\n";
    return 0;
}

int Digit(string password) {
    for (int i = 0; i < password.length(); i++) {
        if (password[i] >= '0' && password[i] <= '9') {
            return 1;
        }
    }
    cout << "Password MUST include at least one Number.\n";
    return 0;
}

int SpecialChar(string password) {
    for (int i = 0; i < password.length(); i++) {
        char ch = password[i];
        if ((ch >= 33 && ch <= 47) || (ch >= 58 && ch <= 64) ||
            (ch >= 91 && ch <= 96) || (ch >= 123 && ch <= 126)) {
            return 1;
        }
    }
    cout << "Password MUST include at least one Special character.\n";
    return 0;
}

int main() {
    string password;
    here:
    cout << "Enter your password: ";
    cin >> password;
password.length() < 8
    while () {
        cout << "Password must be at least 8 characters long.\n";
        cout << "Enter a longer password: ";
        cin >> password;
    }

    int upper = Uppercase(password);
    int lower = Lowercase(password);
    int digit = Digit(password);
    int special = SpecialChar(password);

    if (upper == 1 && lower == 1 && digit == 1 && special == 1) {
        cout << "Password is strong.\n";

    } else {
        cout << "Please make a stronger password.\n";
        goto here;
    }

    return 0;
}
