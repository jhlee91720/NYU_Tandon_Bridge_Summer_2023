#include <iostream>
#include <cmath>
using namespace std;

void analyzeDivisors (int num, int& outCountDivs, int& outSumDivs);
bool isPerfect (int num);

int main () {
    int input;

    cout << "Enter a positive integer greater or equal than 2: ";
    cin >> input;
    
    // perfect numbers checking from 2 to num
    cout << "Perfect numbers between 2 and " << input  << " are: " << endl;;
    for (int i = 2; i <= input; i++) {
        if (isPerfect(i) == true)
            cout << i << endl;
    }
    // Amicable numbers checking from 2 to num
    cout << "Pairs of amicable numbers that are between 2 and " << input << " are: " << endl;
    bool pairDoesNOTExist = true;
    for (int i = 2; i <= input; i++) {
        int countDivs1, sumDivs1;
        int countDivs2, sumDivs2;

        analyzeDivisors(i, countDivs1, sumDivs1);
        analyzeDivisors(sumDivs1, countDivs2, sumDivs2);

        if ((i == sumDivs2) && (i < sumDivs1)) {
            pairDoesNOTExist = false;
            cout << '(' << i << ", " << sumDivs1 << ")" << endl;
        }
    }

    if (pairDoesNOTExist) {
        cout << "none." << endl;
    }

    return 0;
}

bool isPerfect (int num) {
    int countDivs, sumDivs;

    analyzeDivisors (num, countDivs, sumDivs);

    return sumDivs == num;
}

void analyzeDivisors (int num, int& outCountDivs, int& outSumDivs) {
    
    int countDivs = 1 , sumDivs = 1;

    for (int count = 2; count <= pow(num, 0.5); count++) {
        if (num % count == 0) {
            countDivs ++;
            sumDivs += (count + num / count);
        }
        else{
            countDivs ++;
        }
    }

    outCountDivs = countDivs;
    outSumDivs = sumDivs;
    
}

