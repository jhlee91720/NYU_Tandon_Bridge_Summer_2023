#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
using namespace std;

class List;
class Node;

class Individual{
private:
    double paid;
    double owed;
    string name;
public:
    Individual (double new_paid, string new_name) {
        paid = new_paid;
        name = new_name;
    }
    Individual () {
        paid = 0;
        owed = 0;
        name = "";
    }
    double getPaid() const { return paid; }
    double getOwed() const { return owed; }
    string getName() const { return name; }
    void setPaid(double new_paid) { paid = new_paid; }
    void setOwed(double new_owed) { owed = new_owed; }
    void setName(string new_name) { name = new_name; }
};


class Node{
private:
    Individual data;
    Node* prev_node;
    Node* next_node;
    
public:
    Node (const Individual& person = Individual(), Node* prev = nullptr, Node* next = nullptr) {
        data = person;
        prev_node = prev;
        next_node = next; 
    }
    Individual& getData () { return data; }
    Node* getPrev() const { return prev_node; }
    Node* getNext() const { return next_node; }
    friend class List;
};

class List{
    int size;
    Node* head;
    Node* tail;
public:
    List () {
        size = 0;
        head = new Node();
        tail = new Node();
        head->next_node = tail;
        tail->prev_node = head;
    }
    List (const List& rhs) {
        size = 0;
        head = new Node ();
        tail = new Node ();
        head->next_node = tail;
        tail->prev_node = head;
        *this = rhs;
    }
    List& operator= (const List& rhs) {
        if (this == &rhs){
            return *this;
        }

        clearDataNodes();

        Node* temp_1;
        Node* temp_2;
        temp_1 = rhs.head->next_node;
        temp_2 = rhs.tail;

        while (temp_1 != temp_2){
            insertAtTail(temp_1->data);
            temp_1 = temp_1->next_node;
        }

        return *this;
    }
    ~List () {
        clearDataNodes();
        delete head;
        delete tail;
    }
    int getSize () const { return size; }
    Node* getHead () const { return head->next_node; }
    Node* getTail () const { return tail; }

    void insertAfter (const Individual& data, Node* target) {
        Node* temp = new Node(data, target, target->next_node);
        target->next_node = temp;
        temp->next_node->prev_node = temp;
        size++;
    }
    void insertAtTail (const Individual& data) { insertAfter(data, tail->prev_node); }
    Individual removeNode(Node* target) {
        Individual data = target->data;
        target->prev_node->next_node = target->next_node;
        target->next_node->prev_node = target->prev_node;
        size--;

        delete target;
        return data;
    }
    bool isEmpty () const { return (size == 0); }
    void clearDataNodes () {
        while (!isEmpty()){
            removeNode(head->next_node);
        }
    }
};

void calculateAverageAndDiff(List& data_list);
void create3Vectors(List& data_list, vector<Node*>& paid_more, vector<Node*>& paid_less, vector<Node*>& paid_complete);
void finalResult(List& data_list, vector<Node*>& paid_more, vector<Node*>& paid_less, vector<Node*>& paid_complete);


int main () {

    List input_list;
    ifstream reading_file_stream;
    vector<Node*> more;
    vector<Node*> less;
    vector<Node*> zero;

    string file_name;

    cout << "Please enter the file name with .txt at the end: ";
    cin >> file_name;
    reading_file_stream.open(file_name);

    while (reading_file_stream.fail()){
        cout << "ERROR! Failed to open the file." << endl;
        cout << "Please re-enter the file name with .txt at the end: ";
        cin >> file_name;
        reading_file_stream.clear();
        reading_file_stream.open(file_name);
    }

    double paid, owed;
    string name;

    while (reading_file_stream >> paid){
        reading_file_stream.ignore(9999, ' ');
        getline(reading_file_stream, name);
        input_list.insertAtTail(Individual(paid, name));
    }
    
    calculateAverageAndDiff(input_list);
    create3Vectors(input_list, more, less, zero);
    finalResult(input_list, more, less, zero);

    cout << endl << "Process Finished with Exit Code 0." << endl;

    return 0;
}


void calculateAverageAndDiff(List& data_list){
    Node* temp1;
    Node* temp2;
    temp1 = data_list.getHead();
    temp2 = data_list.getTail();

    double sum = 0;
    int count = 0;
  
    while (temp1 != temp2){
        sum += temp1->getData().getPaid();
        count++;
        temp1 = temp1->getNext();
    }

    double avg = sum / count;
    avg = round(avg * 100.0) / 100.0;


    temp1 = data_list.getHead();
    double paid = 0;
    while (temp1 != temp2){
        paid = temp1->getData().getPaid();
        temp1->getData().setOwed(paid - avg);
        temp1 = temp1->getNext();
    }
}

void create3Vectors(List& data_list, vector<Node*>& paid_more, vector<Node*>& paid_less, vector<Node*>& paid_complete){
    Node* temp1;
    Node* temp2;
    temp1 = data_list.getHead();
    temp2 = data_list.getTail();

    while (temp1 != temp2){
        if (temp1->getData().getOwed() > 0){
            paid_more.push_back(temp1);
        } 
        else if (temp1->getData().getOwed() < 0){
            paid_less.push_back(temp1);
        }
        else if (temp1->getData().getOwed() == 0){
            paid_complete.push_back(temp1);
        }

        temp1 = temp1->getNext();
    }

}

void finalResult(List& data_list, vector<Node*>& overpaid, vector<Node*>& underpaid, vector<Node*>& done){
    int overpaid_v_size = overpaid.size();
    int underpaid_v_size = underpaid.size();
    int done_v_size = done.size();

    int i = 0;
    int j = 0;

    double overpaid_num = 0;
    double underpaid_num = 0;
    int overpaid_name_size = 0;
    int underpaid_name_size = 0;
    int done_name_size = 0;
    string overpaid_name = "";
    string underpaid_name = "";
    string done_name = "";
    double decimal = 0;

    if (done_v_size != 0){
        for (int i = 0; i < done_v_size; i++){
            done_name = done[i]->getData().getName();
            done_name_size = done_name.size();

            for (int j = 0; j < done_name_size; j++){
                cout << done_name[j];
            }

            cout << ", you don't need to do anything" << endl;
        }
    }
    

    while (i < overpaid_v_size && j < underpaid_v_size){
        overpaid_num = overpaid[i]->getData().getOwed();
        overpaid_name = overpaid[i]->getData().getName();
        overpaid_name_size = overpaid_name.size();
        underpaid_num = underpaid[j]->getData().getOwed();
        underpaid_name = underpaid[j]->getData().getName();
        underpaid_name_size = underpaid_name.size();
        

        if (overpaid_num >= abs(underpaid_num)){
            for (int i = 0; i < underpaid_name_size; i++){
                cout << underpaid_name[i];
            }
            cout << ", you give ";
            for (int i = 0; i < overpaid_name_size; i++){
                cout << overpaid_name[i];
            }

            decimal = round(abs(underpaid_num) * 100.0) / 100.0;
            
            cout << " $" << decimal;
            

            if (fmod(decimal * 100.0, 100.0) == 0.0){
                cout << ".00";
            }

            else if (fmod(decimal * 100.0, 10.0) == 0.0){
                cout << '0';
            }
            cout << endl;

            overpaid[i]->getData().setOwed(overpaid_num + underpaid_num);
            underpaid[j]->getData().setOwed(0);
            j++;

        }
        else{
            for (int i = 0; i < underpaid_name_size; i++){
                cout << underpaid_name[i];
            }

            cout << ", you give ";

            for (int i = 0; i < overpaid_name_size; i++){
                cout << overpaid_name[i];
            }
            
            decimal = round(abs(overpaid_num) * 100.0) / 100.0;
            
            cout << " $" << decimal;

            if (fmod(decimal * 100.0, 100.0) == 0.0){
                cout << ".00" ;
            }
            else if (fmod(decimal * 100.0, 10.0) == 0.0){
                cout << '0';
            }
            cout << endl;

            overpaid[i]->getData().setOwed(0);
            underpaid[j]->getData().setOwed(overpaid_num + underpaid_num);
            i++;
        }

    }

    cout << endl;

    Node* temp1;
    Node* temp2;
    temp1 = data_list.getHead();
    temp2 = data_list.getTail();

    int count = 0;
    double sum = 0;
    double avg = 0;

    while (temp1 != temp2){
        sum += temp1->getData().getPaid();
        count++;

        temp1 = temp1->getNext();
    }

    avg = sum / count;
    avg = round(avg * 100.0) / 100.0;

    cout << "In the end, you should all have spent $" << avg;

    if (fmod(avg * 100.0, 100.0) == 0.0){
            cout << ".00" ;
    }
    else if (fmod(avg * 100.0, 10.0) == 0.0){
            cout << '0';
    }
    cout << endl;
}