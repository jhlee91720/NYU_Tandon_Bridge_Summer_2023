#include <iostream>
#include <string>
using namespace std;

string day;
double cost;
int hour, minute, length;
char temp;

int main(){
    cout<<"Please enter the day of the week using the first 2 characters of the days (e.g. Mo, Tu, We): "<<endl;
    cin>>day;
    cout<<"Please enter the time the call started in 24-hour format (e.g. 13:30): "<<endl;
    cin>>hour>>temp>>minute;
    cout<<"Please enter the length of the call in minutes: "<<endl;
    cin>>length;

    if(day == "Sa" || day == "Su"){
        cost = 0.15 * length;
        cout<<"The cost of the call is $"<<cost<<endl;
    }else{
        if (hour >= 8 && hour < 18){
            cost = length * 0.4;
            cout<<"The cost of the call is $"<<cost<<endl;
        }else{
            cost = length * 0.25;
            cout<<"The cost of the call is $"<<cost<<endl;
        }
    }
    
    
    return 0;
}