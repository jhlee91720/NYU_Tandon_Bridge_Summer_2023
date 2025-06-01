#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int number_of_guesses_left = 5;
    int max = 100;
    int min = 1;
    int attempt = 0;
    int input;
    int my_number;
    bool end = false;

    srand(time(0));
    my_number = (rand() % 100) + 1;

    // my_number = 25;

    cout << "I thought of a number between " << min << " and " << max << "! Try to guess it." <<endl;
    
    while (end == false){
        if (number_of_guesses_left == 0){
            cout << "Out of guesses! My number is " << my_number << endl;
            end = true;

        }else {
            while (attempt < number_of_guesses_left){
            cout << "Range: [" << min << "," << max <<"], Number of guesses left:" << number_of_guesses_left << endl;
            cout << "Your guess: ";
            cin >> input;
            
                if (input < my_number){
                    cout << "Wrong! My number is bigger." << endl;
                    min = input + 1;
                    number_of_guesses_left--;
                }else if (input > my_number){
                    cout << "Wrong! My number is smaller." << endl;
                    max = input - 1;
                    number_of_guesses_left--;
                }else{
                    cout << "Congrats! You guessed my number in "<< 5 - number_of_guesses_left + 1 << " guesses" << endl;
                    end = true;
                    break;
                }
            }
        }
    }
        


    return 0;

}