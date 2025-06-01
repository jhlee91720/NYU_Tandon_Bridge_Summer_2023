#include <iostream>
#include <string>
using namespace std;

bool is_anagram (string str1, string str2);
void letter_occurrence(string str, int letter_arr[]);

int main () {
    string input_1, input_2;
    bool result = false;

    
    cout << "Enter the first sentence: " << endl;
    getline(cin, input_1);
    cout << "Enter the second sentence: " << endl;
    getline(cin, input_2);


    result = is_anagram(input_1, input_2);


    if (result == false)
        cout << "The two sentences are not anagram to each other. " << endl;
    else 
        cout << "The two sentences are anagram to each other." << endl;

    return 0;
}

bool is_anagram (string str1, string str2){

    const int ALPHABET = 26;
    int str1_arr[ALPHABET] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int str2_arr[ALPHABET] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};


    letter_occurrence(str1, str1_arr);
    letter_occurrence(str2, str2_arr);


    for (int i = 0; i <= ALPHABET; i++){
        if (str2_arr[i] != str1_arr[i]){
            return false;
        }
        else {
            return true;
        }
    }
    
}

void letter_occurrence(string str, int letter_arr[]) {

    for (int i = 0; i <= str.length(); i++){
        if (str[i] >= 65  && str[i] <= 90){ // 'A' = 65 and 'Z' = 90
            letter_arr[str[i] - 65]++;
        }
        else if (str[i] >= 97 && str[i] <= 122){ // 'a' = 97 and 'z' = 122
            letter_arr[str[i] - 97]++;
        }
    }

}