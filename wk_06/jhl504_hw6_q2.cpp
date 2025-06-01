#include <iostream>
using namespace std;

void printShiftedTriangle(int n, int m, char symbol);
void printPineTree(int n, char symbol);

int main() {
    int triangle_number = 0;
    char symbol;

    cout << "Enter number of triangles: ";
    cin >> triangle_number;

    cout << "Enter a symbol: ";
    cin >> symbol;

    printPineTree(triangle_number, symbol);

    return 0;
}

void printShiftedTriangle(int n, int m, char symbol) {
    for (int row = 0; row < n; row++) {
        for (int column = 0; column < m; column++) {
            cout << "-";
        }
        for (int column = n - row; column > 1; column--) {
            cout << "0";
        }
        for (int column = 0; column < 2 * row + 1; column++) {
            cout << symbol;
        }
        cout << endl;
    }
}

void printPineTree(int n, char symbol) {
    for (int row = 1; row <= n; row++) {
        printShiftedTriangle(row + 1, n - row, symbol);
    }
}