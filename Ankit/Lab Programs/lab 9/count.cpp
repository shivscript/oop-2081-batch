#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
ifstream fin("info.txt");
if (!fin) {
    cerr << "Error: Could not open file 'info.txt'" << endl;
    return 1;
}
    string line;
    int lineCount = 0;
    int wordCount = 0;
    while (getline(fin, line)) {
    lineCount++;
    int length = line.length();
    bool inWord = false;
    for (int i = 0; i < length; i++) {
    if (isspace(line[i])) {
    inWord = false;
    } else if (!inWord) {
    wordCount++;
    inWord = true;
    }
    }
    }
    fin.close();
    cout << "Number of lines: " << lineCount << endl;
    cout << "Number of words: " << wordCount << endl;
    return 0;
}