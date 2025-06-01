#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string str);

int main () {
    string input_word;
    bool result;

    cout << "Please enter a word: " ;
    cin >> input_word;

    result = isPalindrome(input_word);

    if (result == true){
        cout << input_word <<" is palindrome." << endl;;
    }else{
        cout << input_word << " is not palindrome." << endl;
    }

    return 0;
}

bool isPalindrome(string str){
    int string_length = str.length();

    for (int i = 0; i <= string_length; i++){
        if (str[i] != str[string_length - i - 1]){
            return false;
        }
    }
    return true;
}