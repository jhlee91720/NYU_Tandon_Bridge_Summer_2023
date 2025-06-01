#include <iostream>
using namespace std;

int main(){

    int input;

    cout << "Please enter a positive integer: ";
    cin >> input;

    for (int x = 0; x < input; x++) {
        int space = x, star = 2 * (input - x) - 1;

        for (int y = 0; y < space; y++) {
            cout << ' ';
        }
        for (int z = 0; z < star; z++) {
            cout << '*';
        }
        cout << endl;
    }



    for (int x = 0; x < input; x++) {
        int space = input - x - 1, star = 2 * x + 1;

        for (int y = 0; y < space; y++) {
            cout << ' ';
        }

        for (int z = 0; z < star; z++) {
            cout << '*';
        }
        cout << endl;
    }

   return 0;
}