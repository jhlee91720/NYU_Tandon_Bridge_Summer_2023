#include <iostream>
#include <string>
using namespace std;

int main () {
    string input, word;
    int start_index, end_index;
    int word_count = 0;
    int letter_arr[26] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    

    cout << "Please enter a line of text: " << endl;
    getline (cin, input);


    for (end_index = 0; end_index <= input.length(); end_index++){
        if (input[end_index] == ' ' || end_index == input.length()){
            word = input.substr(start_index, end_index - start_index);
            for (int i = 0; i < word.length() - 1; i++){
                if (word[i] == ',' || word[i] == '.'){
                    word_count++;
                }
            }
            start_index = end_index + 1;
            word_count++;
        }
    }

    for (int i = 0; i <= input.length(); i++){
        if (input[i] >= 65  && input[i] <= 90){ // 'A' = 65 and 'Z' = 90
            letter_arr[input[i] - 65]++;
        }
        else if (input[i] >= 97 && input[i] <= 122){ // 'a' = 97 and 'z' = 122
            letter_arr[input[i] - 97]++;
        }
    }


    cout << word_count << "\t" << "word(s)." << endl;

    for (int i = 0; i < 26; i++){
        if (letter_arr[i] > 0) {
            cout << letter_arr[i] << "\t" << char (i +'a') << endl;
        }
    }



    return 0;
}

