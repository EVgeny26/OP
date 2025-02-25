#include "flat.h"

FLAT::FLAT(unsigned int number, ADDRESS address, unsigned short square, unsigned short floor, SIDE side, DATA data_sale, unsigned int price, SALE sale):
    number(number), address(address), square(square), floor(floor), side(side), data_sale(data_sale), price(price), sale(sale), price_with_sale(price*(100-sale)/100) {}

FLAT::~FLAT(){}



void FLAT::setPrice(unsigned int newPrice){
    price=newPrice;
    price_with_sale=(price*(100-sale)/100);

}
void FLAT::setSale(SALE sale){
    this->sale=sale;
    price_with_sale=(price*(100-sale)/100);
}



unsigned int FLAT::getNumder(){
    return number;
}
string FLAT::getAddress(){
    return address.get_string();
}
unsigned int FLAT::getSquare(){
    return square;
}
unsigned int FLAT::getFloor(){
    return floor;
}
int FLAT::getSide(){
    return side;
}
string FLAT::getDataSale(){
    return data_sale.get_string();
}
unsigned int FLAT::getPrice(){
    return price;
}
int FLAT::getSale(){
    return sale;
}
unsigned int FLAT::getPriceWithSale(){
    return price_with_sale;
}


void FLAT::print(){
    cout<<number<<' '<<address.get_string()<<' '<<square<<' '<<floor<<' '<<side<<' ';
    cout<<data_sale.get_string()<<' '<<price<<' '<<sale<<' '<<price_with_sale<<endl;
}
void FLAT::printShortInfo(){
    cout<<number<<' '<<address.get_string()<<' '<<square<<endl;
}