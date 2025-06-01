#include<iostream>
using namespace std;

    int quarter;
    int dime;
    int nickel;
    int penny;
    int sum;
    int dollar;
    int cent;

int main(){
    cout<<"Please enter the number of coins:\n# of quarters:";
    cin>>quarter;
    cout<<"# of dimes:";
    cin>>dime;
    cout<<"# of nickels:";
    cin>>nickel;
    cout<<"# of pennies:";
    cin>>penny;
    sum = quarter*25+dime*10+nickel*5+penny;
    dollar = sum / 100;
    cent = sum % 100;
    cout<<"The total is "<<dollar<<" dollars and "<<cent<<" cents.";
    
return 0;
}