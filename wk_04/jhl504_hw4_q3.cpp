#include <iostream>
using namespace std;

int n, input;
int current_digit;
int base, binary;

int main(){
    cout<<"Enter decimal number: "<<endl;
    cin>>input;

    n = input;
    current_digit = 0;
    base = 1;

    while (n != 0){
        current_digit = n % 2;
        binary += current_digit * base;
        base *= 10;
        n /= 2;
    }
    cout<<"The binary representation of "<<input<<" is "<<binary<<endl;

    return 0;
}