#include <iostream>
#include <cmath>
#include <string>
using namespace std;

double a, b, c, x, x1, x2, determinant, solution;

int main(){
    cout<<"Please enter value of a: "<<endl;
    cin>>a;
    cout<<"Please enter value of b: "<<endl;
    cin>>b;
    cout<<"Please enter value of c: "<<endl;
    cin>>c;

    determinant = pow(b, 2.0) - 4 * a * c;
    x1 = (-b + sqrt(determinant))/(2 * a);
    x2 = (-b - sqrt(determinant))/(2 * a);

    if (a==0){
        if (b==0){
            if(c==0){
                cout<<"This equation has infinite solutions."<<endl;
            }else{
                cout<<"This equation has no solutions."<<endl;
            }
        }else{
             if(c==0){
                cout<<"This equation has a single real solution. x = 0"<<endl;
            }else{
                x = -c / b;
                cout<<"This equation has a single real solution. x = "<<x<<endl;
            }
        }   
    }else{
        if (determinant == 0){
            x = -b/(2 * a);
            cout<<"This equation has a single real solution. x = "<<x<<endl;
        }else if (determinant > 0){
            cout<<"This equation has two real solutions. x1 = "<<x1<<" and x2 "<<x2<<endl;
        }else if (determinant < 0){
            cout<<"This equation has no real solution."<<endl;
        }
    }

   
     
    return 0;
    }
    

