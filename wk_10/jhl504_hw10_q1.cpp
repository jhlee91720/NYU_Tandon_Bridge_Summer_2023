#include <iostream>
#include <string>
using namespace std;

void printArr(string arr[], int arrSize){
    cout << "There are " << arrSize << " words in your sentence and the words are [";

    for (int i = 0; i < arrSize; i++){
        if (i == (arrSize - 1)){
            cout << " \"" << arr[i] << "\"]." << endl;
        }
        else {
            cout << "\"" << arr[i] << "\", ";
        }
    }

}

string* createWordsArray(string sentence, int& outWordsArrSize){
    string* arr = new string [outWordsArrSize];
    string word;
    int end_index = 0, start_index = 0, word_count = 0;

    for (end_index = 0; end_index <= sentence.length(); end_index++){
        if (sentence[end_index] == ' ' || end_index == sentence.length()){
            word = sentence.substr(start_index, end_index - start_index);
            arr[word_count] = word;
            word_count++;
            start_index = end_index + 1;
        }
    }
    outWordsArrSize = word_count;

    return arr;
    delete [] arr;
}


int main () {
    string input, word;
    int word_count;
    string* word_array;
    int end_index = 0;
    int start_index = 0;

    cout << "Enter your sentence: " << endl;
    getline (cin, input);

    word_array = createWordsArray(input, word_count);

    printArr(word_array, word_count);

    return 0;
}