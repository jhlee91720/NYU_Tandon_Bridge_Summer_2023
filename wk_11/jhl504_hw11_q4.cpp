#include <iostream>
using namespace std;

void printArray(int arr[], int arrLen) {

    for (int i = 0; i < arrLen; i++) {
        cout << arr[i];

        if (i != arrLen - 1) {
            cout << ", ";
        }
    }
    cout << endl;
}

int findMin(int arr[], int arrSize) {
    if (arrSize <= 3) {
        return arr[arrSize - 1];
    } 
    else {
        int jump1 = findMin(arr, arrSize - 1);
        int jump2 = findMin(arr, arrSize - 2);

        if (jump1 < jump2) {
            return jump1 + arr[arrSize - 1];
        } 
        else {
            return jump2 + arr[arrSize - 1];
        }
    }
}

int main() {
    int arr[] = { 0, 3, 80, 6, 57, 10 };
    int arrSize = sizeof(arr) / sizeof(*arr);


    cout << "Game Board: ";
    printArray(arr, arrSize);


    cout << "Cheapest cost: " << findMin(arr, arrSize) << endl;

    return 0;
}