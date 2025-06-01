#include<iostream>
using namespace std;

int dollar;
int cent;
int sum;
int quarter;
int dime;
int nickel;
int penny;
int after_quarter;
int after_dime;
int after_nickel;

int main(){
    cout<<"Please enter your amount in the format of dollars and cents separated by a space: "<<endl;
    cin>>dollar>>cent;
    
    sum = dollar * 100 + cent;

    quarter = sum / 25;
    after_quarter = sum % 25;

    dime = after_quarter / 10;
    after_dime = after_quarter % 10;

    nickel = after_dime / 5;
    after_nickel = after_dime % 5;

    penny = after_nickel;

    cout<<dollar<<" dollars and "<<cent<<" cents are:"<<endl;
    cout<<quarter<<" quaters, "<<dime<<" dimes, "<<nickel<<" nickels, and "<<penny<<" pennies."<<endl;

return 0;

}