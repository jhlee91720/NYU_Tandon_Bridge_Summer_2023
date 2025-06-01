#include <iostream>
#include <vector>
using namespace std;

vector<int> min_max_merged(vector<int>& v1, vector<int>& v2){
    vector<int> temp;

    int minimum = min(v1[0], v2[0]);
    int maximum = max(v1[1], v2[1]);
    temp.push_back(minimum);
    temp.push_back(maximum);

    return temp;
}

vector<int> min_and_max(vector<int>& v, int low, int high){
    if (low == high){
        vector<int> temp;

        temp.push_back(v[low]);
        temp.push_back(v[high]);
        return temp;
    }
    else {
        int mid = (low + high) / 2;
        vector<int> first_half = min_and_max (v, low, mid);
        vector<int> second_half = min_and_max (v, mid + 1, high);
        return min_max_merged (first_half, second_half);
    }
}


int main (){ 
    vector<int> input_vector;
    int input;
    int vector_size;

    cout << "Please enter the number of integers: ";
    cin >> vector_size;

    cout << "Please enter integers: " ;
    for (int i = 0; i < vector_size; i++){
        cin >> input;
        input_vector.push_back(input);
    }
    
    vector<int> result = min_and_max (input_vector, 0, input_vector.size() - 1);

    cout << "min: " << result[0] << "\t" << "max: " << result[1] << endl;
 
    return 0;
}
