#include <iostream>
#include <vector>
using namespace std;

class Money {
    private:
        long all_cents;
    
    public:

        // constructor
        Money(double dollars){
            all_cents = (long) (dollars*100);
        }

        Money(){}

        // getter
        double get_amount() const { return all_cents * 0.01; }

        friend istream& operator >>(istream& ins, Money& money) {

            char char_to_read, decimal_point;
            long dollars;
            int decimals;
            int cents;
            bool is_negative = false;

            ins >> char_to_read;

            if (char_to_read == '-') {
                is_negative = true;
                ins >> char_to_read;
            }

            ins >> dollars >> decimal_point >> cents;

            if (char_to_read != '$' || decimal_point != '.'|| !(cents >= 0 && cents <= 99)) {  
                cout << "Error! The money is not in proper format..." << endl;
                exit(1);
            }

            // cents = decimals;
            money.all_cents = dollars * 100 + cents;

            if (is_negative) {
                money.all_cents = -1*money.all_cents;
            }

            return ins;
        }

        friend ostream& operator <<(ostream& outs, const Money& money){
            double amount = money.get_amount();

            if (amount < 0) {
                outs << "-$" << amount;
            } else {
                outs << '$' << amount;
            }

            return outs;
        }

        friend Money operator + (const Money& left, const Money& right){
            Money total_amount_object;

            total_amount_object.all_cents = left.all_cents + right.all_cents;

            return total_amount_object;

        }

        friend Money operator - (const Money& left, const Money& right){
            // double left_amount = left.get_amount();
            // double right_amount = right.get_amount();

            // double total_amount = left_amount - right_amount;

            Money total_amount_object;

            total_amount_object.all_cents = left.all_cents - right.all_cents;

            return total_amount_object;

        }

        friend Money operator -(const Money& amount) {
            Money total_amount_object;
            total_amount_object.all_cents = -amount.all_cents;

            return total_amount_object;
        }

};


class Check {
    private:
        int check_number;
        Money check_amount;
        bool is_approved;

    public:
        // constructor
        Check(int check_number_param, double check_amount_param, bool is_approved_param){
            check_number = check_number_param;
            check_amount = Money(check_amount_param);
            is_approved = is_approved_param;
        }
        Check(){}

        // getter
        int get_check_number() {return check_number;}
        double get_check_amount() { return check_amount.get_amount();}
        bool get_approval_status() {return is_approved; }

        // setter
        void set_check_number(int new_check_number) {check_number = new_check_number;}
        void set_check_amount(double new_check_amount) {check_amount = Money(new_check_amount);}
        void set_approval_status(bool new_is_approved) {is_approved = new_is_approved;}

        friend istream& operator >>(istream& ins, Check& check) { 

            string is_cashed;

            ins >> check.check_number >> check.check_amount >> is_cashed;

            if (is_cashed == "y" || is_cashed == "yes" || is_cashed == "Y") {
                check.is_approved = true;
            } else if (is_cashed == "n" || is_cashed == "no" || is_cashed == "N") {
                check.is_approved = false;
            } else {
                cout << "Error illegal form for whether or not a check has been cashed\n";
                exit(1);
            }

            return ins;
        }

        friend ostream& operator << (ostream& outs, Check& check) { 

            outs << "check number: " << check.get_check_number();
            cout << " || check amount: ";
            
            if (check.get_check_amount() < 0){
                cout << "-$";
            } else {
                cout << "$";
            }

            cout << check.get_check_amount();
            cout << endl;

            return outs;
        }

};




int get_the_number_of_withdrawls();
vector<Check> create_a_list_of_withdrawls(int num_of_checks);
int get_the_number_of_deposits();
vector<Money> create_a_list_of_deposits(int num_of_deposits);
Money get_the_old_balance();


Money get_total_amount_of_withdrawls(const vector<Check>& withdrawls, bool is_cashed);
Money get_total_amount_of_deposits(const vector<Money>& deposits);

void print_money(const string& title, const Money& money_to_be_printed);

void display_checks(const vector<Check>& withdrawls, bool is_cashed);


int main (){

    // prompt the use for the number of withdrawls
    int n_of_withdrawls = get_the_number_of_withdrawls();

    // user inputs withdrawls
    vector<Check> withdrawls = create_a_list_of_withdrawls(n_of_withdrawls);

    int num_of_deposits = get_the_number_of_deposits();
    // User also inputs deposits 
    vector<Money> deposits = create_a_list_of_deposits(num_of_deposits);

    // user inputs old balance
    Money old_balance = get_the_old_balance();


    // output 생성
    // 1. get the total amount of approved withdrawls
    Money cashed_check_total = get_total_amount_of_withdrawls(withdrawls, true);
    // 2. get the total amount of yet-to-be-approved withdrawls
    Money uncashed_check_total = get_total_amount_of_withdrawls(withdrawls, false);
    // 3. get the total amount of deposits
    Money deposit_total = get_total_amount_of_deposits(deposits);
    // 4. get the bank balance (old balance + d3eposit - approved withdrawls)
    Money bank_balance = old_balance + deposit_total - cashed_check_total;
    // 5. get the customer balance (old balance + deposit - all withdrawls)
    Money customer_balance = old_balance + deposit_total - (cashed_check_total + uncashed_check_total);

    print_money("cashed checks", cashed_check_total);
    print_money("un-cashed checks", uncashed_check_total);
    print_money("deposits", deposit_total);
    print_money("bank balance", bank_balance);
    print_money("customer balance", customer_balance);

    // 6. display the list of approved withdrawls
    display_checks(withdrawls, true);
    // 7. display the list of yet-to-be-approved withdrawls
    display_checks(withdrawls, false);

    return 0;
}

int get_the_number_of_withdrawls(){
     
    int n_of_checks;

    cout << "What is the number of checks?\t";
    cin >> n_of_checks;

    while (n_of_checks <= 0){

        cout << "ERROR! It must be greater than zero." << endl;
        cout << "What is the number of checks?\t";
        cin >> n_of_checks;

    }
    
    return n_of_checks;

}

int get_the_number_of_deposits(){

    int n_of_deposits;
    cout << "What is the number of deposits?\t";
    cin >> n_of_deposits;

    while (n_of_deposits <= 0){

        cout << "ERROR! It must be greater than zero." << endl;
        cout << "What is the number of deposits?\t";
        cin >> n_of_deposits;

    }
    
    return n_of_deposits;

}


vector<Check> create_a_list_of_withdrawls(int num_of_checks){

    vector<Check> checks;

    for (int i =0; i < num_of_checks; i++){

        cout << "Please enter the amount of the check in the format of check#, amount, cashed(y/n): ";
        
        Check new_check;

        cin >> new_check;

        checks.push_back(new_check);

    }

    return checks;

}

vector<Money> create_a_list_of_deposits(int num_of_deposits){
    vector<Money> deposits;

    for (int i =0; i < num_of_deposits; i++){
        
        cout << "Please enter the amount of the deposit: ";

        Money new_deposit;

        cin >> new_deposit;

        deposits.push_back(new_deposit);

    }

    return deposits;    
}


Money get_the_old_balance(){
    Money old_balance;
    cout << "Please enter the old balance: ";
    cin >> old_balance;

    return old_balance;

}

Money get_total_amount_of_withdrawls(const vector<Check>& withdrawls, bool is_cashed){

    double total_amount = 0.0;
    for (Check withdrawl : withdrawls){
        if (withdrawl.get_approval_status() == is_cashed){
            double check_amount = withdrawl.get_check_amount();
            total_amount += check_amount;
        }
    }
    Money total_amount_object = Money(total_amount);

    return total_amount_object;

}

Money get_total_amount_of_deposits(const vector<Money>& deposits){

    Money total_amount = Money(0.0);
    for (Money deposit : deposits){
        total_amount = total_amount + deposit;
    }

    return total_amount;

}

void print_money(const string& title, const Money& money_to_be_printed){
    cout << title << " : " << money_to_be_printed << endl;
}

void display_checks(const vector<Check>& withdrawls, bool is_cashed){

    cout << endl;
    if (is_cashed){
        cout << "--------------- cashed --------------- " << endl;
    }else{
        cout << "--------------- un-cashed --------------- " << endl;
    }
    for (Check check : withdrawls){
        if (check.get_approval_status() == is_cashed){
            cout << check << endl;
        }
        
    }
    if (is_cashed){
        cout << "--------------- cashed --------------- " << endl;
    }else{
        cout << "--------------- un-cashed --------------- " << endl;
    }
    cout << endl;

}






