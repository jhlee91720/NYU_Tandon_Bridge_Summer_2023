#include <iostream>
using namespace std;

int minInArray1(int arr[], int arrSize){
    int currentMin = arr[arrSize - 1];
    if(arrSize == 1){
        return arr[0];
    }else{
        if(currentMin < minInArray1(arr, arrSize - 1)){
            return currentMin;
        }
        return minInArray1(arr, arrSize - 1);     
    }
}

int minInArray2(int arr[], int low, int high){
    if(high == low){
        return arr[low];
    }
    else {
        if (arr[low] <= arr[high]){
            return minInArray2(arr, low, high - 1);
        }

        return minInArray2(arr, low + 1, high);
        
    }
}

int main () {
    int arr[10] = {7, -2, 14, 12, 3, 6, 2, 1, -9, 15}; 
    int res1, res2, res3, res4;

    res1 = minInArray1(arr, 10);

    res2 = minInArray2(arr, 0, 9);

    cout << res1 << endl; // -9
    cout << res2 << endl; // -9

    res3 = minInArray2(arr, 2, 5);

    res4 = minInArray1(arr+2, 4); //arr+2 is equivalent to &(arr[2])

    cout << res3 << endl; // 3
    cout << res4 << endl; // 3
    return 0;
}