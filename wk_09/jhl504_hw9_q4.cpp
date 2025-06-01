#include <iostream>
using namespace std;

void oddsKeepEvensFlip(int arr[], int arrSize);
void printArray(int arr[], int arrSize);

int main () {

    int arrSize;
    
    cout << "Enter the size of the array: ";
    cin >> arrSize;
    cout << "Enter the sequences of the array, separated by a space: ";

    int arr[arrSize];
    
    for (int i = 0; i < arrSize; i++){
        cin >> arr[i]; 
    }


    oddsKeepEvensFlip (arr, arrSize);


    cout << "The rearranged array is: ";
    printArray(arr, arrSize);

    cout << endl;

    return 0;
}

void printArray(int arr[], int arrSize){
    for (int i = 0; i < arrSize; i++){
        cout << arr[i] << " ";
    }
}

void oddsKeepEvensFlip (int arr[], int arrSize) {

    int* temp = new int [arrSize];
    int i = 0, j = 0; 

    for (i = 0; i < arrSize; i++) {
        if ((arr[i] % 2) != 0) {
            temp[j] = arr[i];
            j++;
        }
    }
    
    for (i = arrSize -1; i >= 0; i--) {
        if ((arr[i] % 2) == 0) {
            temp[j] = arr[i];
            j++;
        }
    }

    for (i = 0; i < arrSize; i++) {
        arr[i] = temp[i];
    }

    delete [] temp;
}


