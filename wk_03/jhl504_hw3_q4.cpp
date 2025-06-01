#include<iostream>
#include <string>
using namespace std;

int main (){
    const int FLOOR_ROUND = 1;
    const int CEILING_ROUND = 2;
    const int ROUND = 3;

    double input;
    int method;
    
    int floor_number, ceiling_number, round_number;

    cout<<"Please enter a Real number: "<<endl;
    cin>>input;
    cout<<"Choose your rounding method: \n 1. Floor round \n 2. Ceiling round \n 3. Round to the nearest whole number"<<endl;
    cin>>method;

    int integer= input;
    double decimal = abs(input - integer);


    switch (method){
        case (FLOOR_ROUND):
            if (input >= 0){
                floor_number = input;
            }else{
                floor_number = input -1;
            }
            cout<<floor_number<<endl;     
            break;
        case (CEILING_ROUND):
            if (input >= 0){
                if (decimal > 0){
                    ceiling_number = input + 1;
                }else if (decimal == 0){
                    ceiling_number = input;
                }
            }else{
                ceiling_number = input;
            }
            cout<<ceiling_number<<endl;
            break;
        case (ROUND):
            if (decimal >= 0.5 && input >= 0){
                round_number = integer + 1;
            }
            else if (decimal < 0.5 && input >= 0){
                round_number = integer;
            }
            else if (input < 0 && decimal < 0.5){
                round_number = integer;
            }else if (input < 0 && decimal >= 0.5){
                round_number = integer -1;
            }
            cout<<round_number<<endl;
            break;
    }

    return 0;
}

