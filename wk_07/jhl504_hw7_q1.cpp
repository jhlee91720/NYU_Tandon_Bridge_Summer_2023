#include <iostream>
using namespace std;

int printMonthCalender (int numOfDays, int startingDay);
void printYearCalender (int year, int startingDay);
bool leapYear (int year);

int main () {
    int year, numOfDays, startingDay, month;
   
    cout << "Enter the year: ";
    cin >> year;
    cout << "Enter the starting day of the year as a number (e.g. MON = 1, TUE = 2, etc): ";
    cin >> startingDay;

    printYearCalender (year, startingDay);

    return 0;
}

bool leapYear (int year) {
    if (year % 4 == 0){
        return true;
    }
    return false;
}

int printMonthCalender (int numOfDays, int startingDay){

    cout << "MON\tTUE\tWED\tTHUR\tFRI\tSAT\tSUN" << endl;

    for (int i = 1; i < startingDay; i++){
        cout << "\t";
    }

    for (int i = 1; i <= numOfDays; i++){
        if ((i + startingDay - 1) % 7 == 0 || i == numOfDays){
            cout << i << endl;
        }else {
            cout << i << "\t";
        }
    }
    return (numOfDays + startingDay - 1) % 7;
}

void printYearCalender (int year, int startingDay) {
    bool is_leap_year;
    int month, numOfDays = 31;

    is_leap_year = leapYear (year);

    for (month = 1; month <= 12; month++){
        if (month == 1){
            cout << "JANUARY " << year << endl;
        }
        else if (month == 2){
            cout << "FEBURUARY " << year << endl;
            if (is_leap_year == true)
                numOfDays = 28;
            else 
                numOfDays = 29;
        }
        else if (month == 3){
            cout << "MARCH " << year << endl;
            numOfDays = 31;
        }
        else if (month == 4){
            cout << "APRIL " << year << endl;
            numOfDays = 30;
        }
        else if (month == 5){
            cout << "MAY " << year << endl;
            numOfDays = 31;
        }
        else if (month == 6){
            cout << "JUNE " << year << endl;
            numOfDays = 30;
        }
        else if (month == 7){
            cout << "JULY " << year << endl;
            numOfDays = 31;
        }
        else if (month == 8){
            cout << "AUGUST " << year << endl;
            numOfDays = 31;
        }
        else if (month == 9){
            cout << "SEPTEMBER "<< year << endl;
            numOfDays = 30;
        }
        else if (month == 10){
            cout << "OCTOBER " << year << endl;
            numOfDays = 31;
        }
        else if (month == 11){
            cout << "NOVEMBER " << year << endl;
            numOfDays = 30;
        }
        else {
            cout << "DECEMBER "<< year << endl;
            numOfDays = 31;
        }
        startingDay = printMonthCalender (numOfDays, startingDay) + 1;  
        cout << endl;      
   }

}
    
