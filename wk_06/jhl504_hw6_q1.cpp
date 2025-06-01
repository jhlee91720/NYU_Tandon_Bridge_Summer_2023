#include <iostream>
using namespace std;


int fib(int n){
    int n2 = 1;
    int n1 =1;
    int sum = 1;

    if (n == 1 || n == 2){
        return 1;
    }
    else {
        for (int i = 3; i <= n; i++) {
            sum = n2 + n1;
            n1 = n2;
            n2 = sum;
        }
        return sum;
    }    
    
}

int main(){
    
    int input;

    cout << "Please enter a positive integer: ";
    cin >> input;

    cout << fib(input) << endl;


    return 0;

}

