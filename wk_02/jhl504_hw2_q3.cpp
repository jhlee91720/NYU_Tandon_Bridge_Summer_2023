#include<iostream>
using namespace std;

int john_day;
int john_hour;
int john_minute;
int bill_day;
int bill_hour;
int bill_minute;
int total;
int minute;
int hour;
int day;

int main(){
    cout<<"Please enter the number of days John has worked: "<<endl;
    cin>>john_day;
    cout<<"Please enter the number of hours John has worked: "<<endl;
    cin>>john_hour;
    cout<<"Please enter the number of minutes John has worked: "<<endl;
    cin>>john_minute;

    cout<<"Please enter the number of days Bill has worked: "<<endl;
    cin>>bill_day;
    cout<<"Please enter the number of hours Bill has worked: "<<endl;
    cin>>bill_hour;
    cout<<"Please enter the number of minutes Bill has worked: "<<endl;
    cin>>bill_minute;
    
    total = john_day * 1440 + john_hour * 60 + john_minute + bill_day * 1440 + bill_hour * 60 + bill_minute;

    day = total / 1440;
    hour = (total % 1440) / 60;
    minute = (total % 1440) % 60;

    cout<<"The total time both of them worked together is: "<<day<<" days, "<<hour<<" hours, and "<<minute<<" minutes."<<endl;

return 0;

}