#include <iostream>
#include <string>
using namespace std;

int n, input;
string roman_numeral = "";

int main(){
    cout<<"Enter decimal number: "<<endl;
    cin>>input;
    n = input;
    while (n != 0){
        if (n >= 1000){
            roman_numeral += "M";
            n -=1000;
        }else if (n >= 500){
            roman_numeral += "D";
            n -= 500;
        }else if ((n >= 100) && (n <= 500)){
            roman_numeral += "C";
            n -= 100;
        }else if (n >= 50){
            roman_numeral += "L";
            n -= 50;
        }else if ((n >= 10) && (n <= 50)){
            roman_numeral += "X";
            n -= 10;
        }else if (n >= 5){
            roman_numeral += "V";
            n -= 5;
        }else if ((n >= 1) && (n <= 5)){
            roman_numeral += "I";
            n -= 1;
        }else if (n <= 0){
            cout<<"please put a positive integer."<<endl;
            cin>> n;
        }
    }

    cout<<input<<" is "<<roman_numeral<<endl;
    
    return 0;
}