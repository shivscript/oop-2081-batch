#include <iostream>
using namespace std;
void testException(int code) {
    if (code == 1) {
        throw 42; // int exception
    }
    else if (code == 2) {
        throw 'X'; // char exception
    }
    else if (code == 3) {
        throw 3.14; // double (not explicitly caught)
    }
    else {
        cout << "No exception thrown." << endl;
    }
}

int main() {
    int choice;
    cout << "Enter 1 (int), 2 (char), or 3 (double) to throw an exception: ";
    cin >> choice;

    try {
        testException(choice);
    }
    catch (int e) {
        cout << "Caught int exception: " << e << endl;
    }
    catch (char e) {
        cout << "Caught char exception: " << e << endl;
    }
    catch (...) {
        cout << "Caught an unknown or unexpected exception!" << endl;
    }

    cout << "Program continues after handling exception." << endl;
    return 0;
}
