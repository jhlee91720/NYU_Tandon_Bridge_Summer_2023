#include <iostream>
#include <string>
using namespace std;

string name, status;
int graduation_year, current_year, status_year;

int main(){
    cout<<"Please enter your name: "<<endl;
    cin>>name;
    cout<<"Please enter your graduation year: "<<endl;
    cin>>graduation_year;
    cout<<"Please enter current year: "<<endl;
    cin>>current_year;

    status_year = graduation_year - current_year;

    if(status_year > 4)
        cout<<name<<", you are not in college yet."<<endl;
    else if(status_year==4)
        cout<<name<<", you are a freshmen."<<endl;
    else if(status_year==3)
        cout<<name<<", you are a sophomore."<<endl;
    else if(status_year==2)
        cout<<name<<", you are a junior."<<endl;
    else if (status_year==1)
        cout<<name<<", you are a senior."<<endl;
    else 
        cout<<name<<", you are graduated."<<endl;

    return 0;
}