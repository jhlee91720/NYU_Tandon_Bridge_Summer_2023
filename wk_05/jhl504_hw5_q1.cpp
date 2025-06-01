#include <iostream>
using namespace std;

int main(){

    int input, output; 

    cout<<"Please enter a positive integer: "<<endl;
    cin>>input;

    output = 1;

    for(int row = 1; row <= input; row++){
        for (int column = 1; column <= input; column++){
            cout<<output<<"\t";
            output = output + 1;
        }
        cout<<endl;
    }
    return 0;
}