#include<iostream>
using namespace std;

int num1, num2, sum, difference, product, quotient, mod; 
double fraction;

int main(){
    cout<<"Please enter two positive integers, separated by a space: "<<endl;
    cin>>num1>>num2;
    
    sum = num1 + num2;
    difference = num1 - num2;
    product = num1 * num2;
    fraction = (double) num1 / (double) num2;
    quotient = num1 / num2;
    mod = num1 % num2;

    cout<<num1<<" + "<<num2<<" = "<<sum<<endl;
    cout<<num1<<" - "<<num2<<" = "<<difference<<endl;
    cout<<num1<<" * "<<num2<<" = "<<product<<endl;
    cout<<num1<<" / "<<num2<<" = "<<fraction<<endl;
    cout<<num1<<" div "<<num2<<" = "<<quotient<<endl;
    cout<<num1<<" mod "<<num2<<" = "<<mod<<endl;
    
    return 0;

}