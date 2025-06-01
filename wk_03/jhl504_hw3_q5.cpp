#include <iostream>
#include <cmath>

using namespace std;

double weight, height, body_index;

int main(){
    cout<<"Please enter weight (in pounds): "<<endl;
    cin>>weight;
    weight = weight * 0.453592;

    cout<<"Please enter height (in inches): "<<endl;
    cin>>height;
    height = height * 0.0254;

    body_index = weight / pow(height,2);

    if (body_index < 18.5){
        cout<<"The weight status is underweight."<<endl;
    }else if(body_index >= 18.5 && body_index < 25){
        cout<<"The weight status is normal."<<endl;
    }else if(body_index >= 25 && body_index <30){
        cout<<"The weight status is overweight."<<endl;
    }else{
        cout<<"The weight status is obese."<<endl;
    }


    return 0;
}