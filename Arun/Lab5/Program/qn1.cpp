/*Define a class string and use + and > operators to concatenate and compare two strings respectively.*/
#include <iostream>
#include <cstring>
using namespace std;
class String {
private:
char str[100];
public:
String() {
str[0] = '\0';
}
String(const char* s) {
strcpy(str, s);
}
void input() {
cout << "Enter string: ";
cin >> str;
}
void display() {
cout << str << endl;
}
String operator+(const String& s) {
String result;
strcpy(result.str, str);
strcat(result.str, s.str);
return result;
}
bool operator>(const String& s) {
return strcmp(str, s.str) > 0;
}
};
int main() {
String s1, s2, s3;
cout << "For String 1:\n";
s1.input();
cout << "For String 2:\n";
s2.input();
cout << "String 1: ";
s1.display();
cout << "String 2: ";
s2.display();
s3 = s1 + s2;
cout << "Concatenated String: ";
s3.display();
if (s1 > s2)
cout << "String 1 is greater than String 2" << endl;
else
cout << "String 1 is not greater than String 2" << endl;
return 0;
}
