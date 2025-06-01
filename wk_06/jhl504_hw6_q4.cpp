#include <iostream>
#include <cmath>
using namespace std;

void printDivisors(int num){
    for (int count = 1; count < sqrt(num); count++){
        if (num % count == 0)
            cout << count << " ";
    }
    for (int count = sqrt(num); count >= 1; count--){
        if (num % count == 0)
            cout << num / count << " ";
    }
    cout << endl;
}

int main(){
    int input;
    int result;

    cout << "Please enter a positive integer >= 2: ";
    cin >> input;

    printDivisors(input);

    return 0;
}
