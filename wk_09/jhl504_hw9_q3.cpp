#include <iostream>
using namespace std;

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize);
int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr);
void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize);
void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr);
void printArray(int arr[], int arrSize);

void printArray(int arr[], int arrSize){
    for(int i = 0; i < arrSize; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main () {

    cout << "The original arrary is: " << endl;
        int arr_size = 6;
        int arr[] = {3, -1, -3, 0, 6, 4};
    printArray(arr, arr_size);

    cout << "getPosNum1: ";
    int arr_size_1;
    int* arr_1;
    arr_1 = getPosNums1 (arr, arr_size, arr_size_1);
    printArray(arr_1, arr_size_1);

    cout << "getPosNum2: ";
    int arr_size_2;
    int* arr_2;
    arr_2 = getPosNums2 (arr, arr_size, &arr_size_2); 
    printArray(arr_2, arr_size_2);

    cout << "getPosNum3: ";
    int arr_size_3;
    int* arr_3;
    getPosNums3(arr, arr_size, arr_3, arr_size_3);
    printArray(arr_3, arr_size_3);


    cout << "getPosNum4: ";
    int arr_size_4;
    int* arr_4;
    getPosNums4(arr, arr_size, &arr_4, &arr_size_4);
    printArray(arr_4, arr_size_4);

    delete [] arr_1;
    delete [] arr_2;
    delete [] arr_3;
    delete [] arr_4;

    return 0;
}

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize){
    int* temp = new int [arrSize];
    int j = 0;

    for(int i = 0; i < arrSize; i++){
        if(arr[i] > 0){
            temp[j] = arr[i];
            j++;
        }
    }

    outPosArrSize = j;

    return temp;
}

int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr){
    int j = 0;
    int* temp = new int [arrSize];

    for(int i = 0; i < arrSize; i++){
        if(arr[i] > 0){
            temp[j] = arr[i];
            j++;
        }
    }
    
    *outPosArrSizePtr = j;
    
    return temp;

}

void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize){
    int j = 0;
    int* temp = new int[arrSize];

    for(int i = 0; i < arrSize; i++){
        if(arr[i] > 0){
            temp[j] = arr[i];
            j++;
        }
    }

    outPosArr = temp;
    outPosArrSize = j;

}

void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr){
    int j = 0;
    int* temp = new int [arrSize];

    for(int i = 0; i < arrSize; i++){
        if(arr[i] > 0){
            temp[j] = arr[i];
            j++;
        }
    }

    *outPosArrPtr = temp;
    *outPosArrSizePtr = j;

}


