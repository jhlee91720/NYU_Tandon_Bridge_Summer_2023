#include <iostream>
using namespace std;

int n, current_digit;
int even_digit, odd_digit;
int counter, temp;


int main(){
    cout<<"Please enter a positive integer: "<<endl;
    cin>>n;

    for (counter = 1; counter <= n; counter++){

        even_digit = 0;
        odd_digit = 0;
        temp = counter;
        
        while (temp > 0){
            current_digit = temp % 10;
                if (current_digit %2 == 0){
                    even_digit++;
                }else{
                    odd_digit++;
                }
            temp /= 10;  
        }
        if (even_digit > odd_digit){
            cout<<counter<<endl;
        }
    }    
    return 0;
}