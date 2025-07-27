#include <iostream>
    #include <string>
    using namespace std;
    int main() {
    try {
        int choice;
    cout << "Enter 1 to throw int,2 to throw char,3 to throw string: ";
        cin >> choice;
      if (choice == 1)
            throw 100;        
        else if (choice == 2)
            throw 'W';         
        else if (choice == 3)
            throw string("This is a string exception.");  
        else
            cout << "Invalid choice!" << endl;
    }
    catch (int e) {
        cout << "Integer exception: " << e << endl;
    }
    catch (char e) {
        cout << "Char exception: " << e << endl;
    }
    catch (string &e) {
        cout << "String exception: " << e << endl;
    }
    cout << "Program continues after exception handling." << endl;
      return 0;
}