#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int PIN_generated(int number[]);

const int PIN[5] = {1, 2 ,3, 4, 5};

int main() {
    int number[10];

    cout << "Please enter your PIN according to the following mapping: \n PIN: 0 1 2 3 4 5 6 7 8 9 \n Num: ";
    
    srand(time(0));

    for (int i = 0; i < 10; i++) {
        number[i] = (rand() % 3) + 1;
        cout << number[i] << ' ';
    }

    cout << endl;

    int input;

    cin >> input;

    if (input == PIN_generated(number)) {
        cout << "Your PIN is correct\n";
    } else {
        cout << "Your PIN is not correct\n";
    }

    return 0;
}

int PIN_generated(int number[]) {
    int encrypted_PIN = 0;

    for (int i = 0; i < 5; i++) {
        encrypted_PIN = 10 * encrypted_PIN + number[PIN[i]];
    }
    return encrypted_PIN;
}