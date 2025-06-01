#include <iostream>
using namespace std;

void reverseArray(int arr[], int arrSize);
void removeOdd(int arr[], int& arrSize);
void splitParity(int arr[],int arrSize);
void printArray(int arr[], int arrSize);

int main() {

    int arr1[10] = {9, 2, 14, 12, -3, 7};
    int arr1Size = 6;

    // reverseArray(arr1, arr1Size);
    // printArray(arr1, arr1Size);

    // removeOdd(arr1, arr1Size);
    // printArray(arr1, arr1Size);

    splitParity(arr1, arr1Size);
    printArray(arr1, arr1Size);

    return 0; 
}

void printArray(int arr[], int arrSize){
    int i;
    for (i = 0; i < arrSize; i++) {
        cout<<arr[i]<<' ';
    }
    cout<<endl;
}


void reverseArray(int arr[], int arrSize){
    int swap;
    int i;

    for (i = 0; i <= arrSize /2; i++){

            swap = arr[i];
            arr[i] = arr[arrSize - 1];
            arr[arrSize - 1] = swap;

            arrSize--;
    }
}

void removeOdd(int arr[], int& arrSize){
    int j = 0;

    for (int i = 0; i < arrSize; i++){
        if(arr[i] % 2 == 0){
            arr[j] = arr[i];
            j++;
        }
    }
    arrSize = j;
}

void splitParity(int arr[],int arrSize){
    int j = 0;
    int k = arrSize;
    int new_arr[arrSize];

    for (int i = 0; i < arrSize; i++) {
        if(arr[i] % 2 == 1){
            new_arr[j] = arr[i];
            j++;
        }
        else{
            new_arr[k - 1] = arr[i];
            k--;
        }
    }
    for (int m = 0; m < arrSize; m++){
        arr[m] = new_arr[m];
    }
}


