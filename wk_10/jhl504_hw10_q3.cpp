#include <iostream>
#include <vector>
using namespace std;

void main1();
void main2();

int main(){
    cout << "part A" << endl;
    main1();

    cout << "part B" << endl;
    main2(); 

    return 0;
}

void main1(){
    const int arr_size_original = 100;
    bool STOP = true;
    int count = 0;
    int search_number, i = 0, j = 0;
    int* arr = new int[arr_size_original];
    
    cout << "Please enter a sequence of positive integers, each in a separate line.\nEnd you input by typing -1: " << endl;

    while (STOP == true) {
        cin >> arr[i];
        if(arr[i] < 0){
            STOP = false;
        }
        else{
            count++;
            i++;
        }
    }

    cout << "Please enter a number you want to search: ";
    cin >> search_number;
    int* create_array = new int[count];
    for(int i = 0; i < count; i++){
        if(search_number == arr[i]){
            create_array[j++] = i;
        }
    }
    if(j > 0){
        cout << "The number appears in lines: ";
            for(int i = 0; i < j; i++){
                cout << create_array[i] + 1 << " ";
            }
            cout << endl;
    }
    else{
        cout << "The number does not appear in the sequence" << endl;
    }
    delete [] create_array;
}


void main2(){

vector<int>arr; 
vector<int>create_array;
int search_number;

cout << "Please enter a sequence of positive integers, each in a separate line.\nEnd you input by typing -1: " << endl;

int input;
cin >> input;

while (input > 0) {
    arr.push_back(input);
    cin >> input;
}

cout << "Please enter you want to search: " << endl;
cin >> search_number;

for(unsigned int i = 0; i < arr.size(); i++){
    if(arr[i] == search_number){
        create_array.push_back(i);
    }
}

if(create_array.size() > 0){
    cout << search_number << " appears in lines: ";
    for(unsigned int i = 0; i < create_array.size(); i++){
        cout << create_array[i] + 1<< " ";
    }
    cout << endl;
}
else{
    cout << "The number does not appear in the sequence " << endl;
}
}

