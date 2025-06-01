#include <iostream>
#include <fstream>
#include <vector>
#include <string>
// #include <cctype>
// #include <cstdlib>
// #include <queue>
#include <algorithm>
using namespace std;


template <class T>
class Queue {
    private:
        vector <T> data;
        int front_index;
        int back_index;
        int size;
    public:
        //constructor
        Queue () {
            front_index = 0;
            back_index = 0;
            size = 0;
        }
        //member functions
        void enqueue (T item) {
            data.push_back(item);
            size++;
            back_index = data.size() - 1;
        }
        T dequeue () {
            T temp = data[front_index];
            front_index++;
            size--;

            if (isEmpty()){
                clear();
            }
            return temp;
        }
        T topFront () {
            return data[front_index];
        }
        T topBack () {
            return data[back_index];
        }
        bool isEmpty () {
            return (data.size() == 0);
        }
        void clear () {
            data.clear();
            front_index = 0;
            back_index = 0;
            size = 0;
        }
        void print () {
            for (int i = front_index; i < front_index + size; i++){
                cout << data[i] << " ";
            }
            cout << endl;
        }
        //getters
        int getFrontIndex () {
            return front_index;
        }
        int getBackIndex () {
            return back_index;
        }
        int getSize () {
            return size;
        }
        //setters -- no need b/c dequeue and enqueue
};


int main(){
    Queue<int> Q_int;
    int Q_int_size;
    int value;

    cout << "Please enter the size of the vector: ";
    cin >> Q_int_size;
    cout << "Enter the integers: ";
    for (int i = 0; i < Q_int_size; i++){
        cin >> value;
        Q_int.enqueue(value);
    }
    cout << "Printing the vector..." << endl;
    Q_int.print();
    cout << endl;

    cout << "Removing the first value..." << endl;
    Q_int.dequeue();
    cout << "After removing first in queue, the first value is: " << Q_int.topFront() << ", the last value is: " << Q_int.topBack() << ", and the new size is: " << Q_int.getSize() << endl;
    cout << "Printing the vector..." << endl;
    Q_int.print();

    cout << "Clearing the vector...";
    Q_int.clear();
    cout << "After clearing, the size is: " << Q_int.getSize();
    if(Q_int.isEmpty()){
        cout << " and the queue is empty" << endl;
    }
    else{
        cout << "and the queue is not empty" << endl;
    }

    Q_int.enqueue(-62);
    Q_int.enqueue(2);
    cout << "Pushed two values. Front is now: " << Q_int.topFront();
    cout << " and the size is: " << Q_int.getSize() << endl;
    cout << "Printing the vector..." << endl;
    Q_int.print();    

    return 0;
}