#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int x, y, counter_a, counter_b;

    
    cout<<"section a"<<endl;

    cout<<"Please enter a positive integer: "<<endl;
    cin>>x;
    
    counter_a = 1;

    while (counter_a <= 2*x){
        if (counter_a % 2 == 0){
            cout<<counter_a<<endl;
            counter_a ++;
        }else{
            counter_a ++;
        }
    }




    cout<<"section b"<<endl;

    cout<<"Please enter a positive integer: "<<endl;
    cin>>y;
    
    for (counter_b = 1; counter_b <= 2*y; counter_b++){
        if (counter_b % 2 == 0){
            cout<<counter_b<<endl;
        }
    }



    return 0;
    
}
