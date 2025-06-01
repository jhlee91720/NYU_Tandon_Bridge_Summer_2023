#include <iostream>
#include <string>
using namespace std;

bool is_digit_string (string word);

int main () {
    string input_string, word, digit_string;
    int start_index = 0;
    int end_index = 0;
    int length;
    int index;

    cout << "Please enter a line of text: " << endl;
    getline(cin, input_string);
    length = input_string.length();
    
    for (end_index = 0; end_index <= length; end_index++){
        if (input_string[end_index] == ' ' || end_index == length){
            word = input_string.substr(start_index, end_index - start_index); 

            bool is_digit_only = is_digit_string(word); 

            if (is_digit_only){
                for (index = 0; index < word.length(); index++){
                    word[index] = 'x';
                }
            }

            cout << word << " ";

            start_index = end_index + 1;

        }

    }
    cout << endl;
    return 0;
}



bool is_digit_string (string word){
    bool is_digit_only = true;
    int index;
    int length = word.length();
    string digit_string;

    for (index = 0; index < length; index++){
        if(!(word[index] >= '0' && word[index] <= '9')){
            is_digit_only = false;
        }
    }
    return is_digit_only;
}


