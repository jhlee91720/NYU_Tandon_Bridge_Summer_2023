#include <iostream>
using namespace std;

int minInArray(int arr[], int arrSize);

int main () {
    int input;
    int i;
    int minimum;
    int index;

    int arr[20];

    cout << "Please enter 20 integers separated by a space: " << endl;

    for (i = 0; i < 20; i++){
        cin >> input;
        arr[i] = input;
    }

    minimum = minInArray(arr, 20);

    cout << "The minimum value is " << minimum << ", and it is located in the following indices: " ;

       for (i = 0; i < 20; i++){
        if (arr[i] == minimum){
            cout << i << " " ;
        }
    }
    return 0;
}

int minInArray(int arr[], int arrSize){
    int i;
    int minimum = arr[0];

    for (i = 1; i < arrSize; i++){
        if (arr[i] < minimum){
            minimum = arr[i];
        }
    }
    return minimum;
}

