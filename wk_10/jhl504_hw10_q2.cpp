#include <iostream>
using namespace std;

int* findMissing(int arr[], int n, int& resArrSize);
void printArr(const int arr[], int arrSize);

int main() {
    const int size = 6;
    int arr[6] = {3, 1, 3, 0, 6, 4};

    cout << "The original array is: " ;
    printArr(arr, size);

    int newSize;
    int* newArr = findMissing(arr, size, newSize);
    
    cout << "There are " << newSize << " numbers missing and the numbers are: ";

    printArr(newArr, newSize);


    delete [] newArr;

    return 0;
}

int* findMissing(int arr[], int n, int& resArrSize) {
    int* temp = new int[n + 1]();

    for (int i = 0; i < n; i++) {
        temp[arr[i]]++;
    }

    int* newArr = new int[n];
    int count = 0;

    for (int i = 0; i < n + 1; i++) {
        if (temp[i] == 0) {
            newArr[count++] = i;
        }
    }

    resArrSize = count;

    delete [] temp;

    return newArr;
}

void printArr(const int arr[], int arrSize) {
    cout << "[";
    for (int i = 0; i < arrSize; i++) {
        cout << arr[i];
        
        if (i != arrSize - 1) {
            cout << ", ";
        }
    }
    cout << "]." << endl;

}