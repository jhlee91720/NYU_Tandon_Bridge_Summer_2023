#include <iostream>
using namespace std;

void printTriangle(int n){
    if (n == 1){
        cout << "*";
    }
    else {
        printTriangle(n - 1);
        for (int i = 1; i <= n; i++){
            cout << "*";
        }
    }
    cout << endl;
}

void printOppositeTriangles(int n){
    if (n == 1){
        cout << "*" << endl;
        cout << "*" << endl;
    }
    else {
        for (int i = 1; i <= n; i++){
            cout << "*";
        }
        cout << endl;

        printOppositeTriangles(n - 1);

        for (int i = 1; i <= n; i++){
            cout << "*";
        }

        cout << endl;
    }
}

void printRuler(int n){
    if (n == 1){
        cout << "-" << endl;
    }
    else {
        printRuler(n - 1);
        for (int i = 0; i < n; i++){
            cout << "-";
        }
        cout << endl;
        printRuler(n - 1);

    }
}


int main () {
    int input;

    cout << "Enter a number: " ;
    cin >> input;

    cout << "part A" << endl;
    printTriangle (input);
    cout << endl;

    cout << "part B" << endl;
    printOppositeTriangles(input);
    cout << endl;

    cout << "part C" << endl;
    printRuler(input);
    cout << endl;


    return 0;
}