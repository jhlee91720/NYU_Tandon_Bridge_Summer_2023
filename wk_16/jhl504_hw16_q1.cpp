#include <iostream>
#include <fstream>
#include <string>
#include <stack>
using namespace std;

bool symbolBalanceChecker (ifstream& in_stream){
    stack <char> symbol_stack;
    string word;
    int word_size = 0;
    bool is_reading_file = false;
    bool is_empty = false;

    while (in_stream >> word){
        if (word == "begin" || word == "Begin" || word == "BEGIN") {
            is_reading_file = true;
        }
        else if (word == "end" || word == "End" || word == "END") {
            is_empty = symbol_stack.empty();
            if (is_empty == false)
                return false; 
            else 
                return true;
        }
        else {
            if (!is_reading_file)
                return false;

            word_size = word.size();

            for (int i = 0; i < word_size; i++){
                if (word[i] == '[' || word[i] == '{' || word[i] == '('){
                    symbol_stack.push(word[i]);
                }

                if (word[i] == ']'){
                    if (symbol_stack.empty() == false && symbol_stack.top() == '[')
                        symbol_stack.pop();
                    else
                        return false;
                }
                if (word[i] == '}'){
                    if (symbol_stack.empty() == false && symbol_stack.top() == '{') 
                        symbol_stack.pop();
                    else 
                        return false;
                }
                if (word[i] == ')'){
                    if (symbol_stack.empty() == false && symbol_stack.top() == '(')
                        symbol_stack.pop();
                    else
                        return false;
                } 
            }
        }
    }
    return false;
}

int main () {
    string file_name;
    ifstream in_stream;

    cout << "please enter the file name: ";
    cin >> file_name;

    in_stream.open(file_name);

    while (in_stream.fail()){
        cout << "ERROR! Please enter the correct file name: ";
        cin >> file_name;
        in_stream.clear();
        in_stream.open(file_name);
    }

    bool result = symbolBalanceChecker (in_stream);

    if (result == true)
        cout << "the symbols match!" << endl;
    else
        cout << "the symbols do not match!" << endl;
    return 0;
}