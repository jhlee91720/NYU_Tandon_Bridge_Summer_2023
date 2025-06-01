#include <iostream>
#include <string>
using namespace std;

int main () {
    string first_name, middle_name, last_name;

    cout << "Please enter your first, middle, and last names in order separated by a space: ";
    cin >> first_name >> middle_name >> last_name;

    cout << last_name << ", " << first_name << " " << middle_name[0] << "." << endl;

    return 0;
}