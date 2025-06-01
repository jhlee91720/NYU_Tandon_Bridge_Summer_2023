#include<iostream>
using namespace std;

    double price_item_1, price_item_2, tax_rate, base_price, discount_price, total_price;
    char club_card;

int main(){
    cout<<"Enter price of first item: "<<endl;
    cin>>price_item_1;
    cout<<"Enter price of second item: "<<endl;
    cin>>price_item_2;
    cout<<"Does customer have a club card? (Y/N): "<<endl;
    cin>>club_card;
    cout<<"Enter tax rate, e.g. 5.5 for 5.5% tax: "<<endl;
    cin>>tax_rate;
    
    base_price = price_item_1 + price_item_2;
    cout<<"Base price: "<<base_price<<endl;
   
    if(price_item_1 > price_item_2)
        price_item_2 *= 0.5;
    else if(price_item_1 < price_item_2)
        price_item_1 *= 0.5;
    else if(price_item_1 == price_item_2)
        price_item_1 *= 0.5;
        
    discount_price = price_item_1 + price_item_2;

    if(club_card == 'Y' || club_card == 'y')
        discount_price *= 0.9;
    else if(club_card == 'N' || club_card == 'n')
        discount_price *= 1;
    else
        cout<<"Wrong input."<<endl;
     
    cout<<"Price after discounts: "<<discount_price<<endl;
    
    total_price = discount_price * tax_rate/100 + discount_price;

    cout<<"Total price: "<<total_price<<endl;

    return 0;


}