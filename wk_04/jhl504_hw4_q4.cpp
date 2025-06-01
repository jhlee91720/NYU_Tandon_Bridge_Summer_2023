#include <iostream>
#include <cmath>
using namespace std;

double length; 
double sequence;
double geometric_mean, product;
bool is_the_end_of_sequence;
int counter = 0;

// int main(){
//     cout<<"Please enter the length of the sequence: "<<endl;
//     cin>>length;
//     cout<<"Please enter your sequence (separated by enter): "<<endl;

//     product = 1.0;

//     for (int count = 1; count <= length; count++){
//         cin>>sequence;
//         product *= sequence;
//     }
//     geometric_mean = pow(product, 1.0/length);
    
//     cout<<"geometric mean is "<<geometric_mean<<endl;
    
//     return 0;
// }

int main(){
    cout<<"Please enter a non-empty sequence of positive integers, each one in a separate line. End your sequence by typing -1: "<<endl;
    
    product = 1.0;
    is_the_end_of_sequence = false;

    while (is_the_end_of_sequence==false){
        cin>>sequence;
        if (sequence == -1){
            is_the_end_of_sequence=true;
        }else{
            product *= sequence;
            counter++;
        } 
    }
    geometric_mean = pow(product, 1.0/(double) counter);
    
    cout<<"geometric mean is "<<geometric_mean<<endl;
    
    return 0;
}

// int main () {
//     cout<<"Please enter a non-empty sequence of positive integers, each one in a separate line. End your sequence by typing -1: "<<endl;
    
//     product = 1.0;
//     is_the_end_of_sequence = false;
//     counter = 0;

//     while (is_the_end_of_sequence == false){
//         cin >> sequence;
//         if (sequence == -1){
//             is_the_end_of_sequence = true;
//         }else{
//             while (sequence >= 0){
//                 product *= sequence;
//                 counter++;
//             }
//         }
//     }
//     geometric_mean = pow(product, 1.0/counter);
    
//     cout<<"geometric mean is "<<geometric_mean<<endl;
//     return 0;
// }