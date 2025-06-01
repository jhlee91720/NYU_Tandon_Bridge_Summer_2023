#include <iostream>
#include <cmath>
using namespace std;

int sumOfSquares(int arr[], int arrSize);
bool isSorted(int arr[], int arrSize);

int main () {
    int arrSize;
    int sum;
    bool ordered;
    
    cout << "Enter array size: ";
    cin >> arrSize;

    int arr[arrSize];
    cout << "Enter sequence: " ;
    for (int i = 0; i < arrSize; i++){
        cin >> arr[i];
    }

    sum = sumOfSquares(arr, arrSize);

    cout << "sum of squares: " << sum << endl;

    ordered = isSorted(arr, arrSize);
    if (ordered == true){
        cout << "ordered?: Yes" << endl;
    }
    else{
        cout << "ordered?: No" << endl;
    }

    return 0;
}

int sumOfSquares(int arr[], int arrSize){
    int sum;
    if (arrSize == 1){
        return pow(arr[0], 2);
    }
    else {
        for (int i = 0; i < arrSize; i++){
            sum = pow(arr[i], 2) + sumOfSquares(arr, arrSize - 1);
        }
    }
    return sum;
}

bool isSorted(int arr[], int arrSize){
    
    if (arrSize == 1){
        return true;
    }
    else {
        if (arr[arrSize-1] >= arr[arrSize - 2]){
            return isSorted(arr, arrSize - 1);
        } else {
            return false;
        }
    }
}
