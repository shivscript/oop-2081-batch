/*Write a program to add two matrices by overloading the + operator.*/
#include <iostream>
using namespace std;

class Matrix {
private:
    int mat[3][3];

public:
    void input() {
        cout << "Enter elements of 3x3 matrix:\n";
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                cin >> mat[i][j];
    }
    Matrix operator+(Matrix m) {
        Matrix result;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                result.mat[i][j] = mat[i][j] + m.mat[i][j];
        return result;
    }

    void display() {
        cout << "Matrix:\n";
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++)
                cout << mat[i][j] << " ";
            cout << endl;
        }
    }
};
int main() {
    Matrix A, B, C;

    cout << "Input Matrix A:\n";
    A.input();

    cout << "Input Matrix B:\n";
    B.input();

    C = A + B;
    cout << "\nResultant Matrix after Addition:\n";
    C.display();

    return 0;
}
