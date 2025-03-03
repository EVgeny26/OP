#include "flat.h"


FLAT::FLAT(){}

FLAT::FLAT(unsigned int number, ADDRESS address, unsigned short square, unsigned short floor, SIDE side, DATE date_sale, unsigned int price, SALE sale):
    number(number), address(address), square(square), floor(floor), side(side), date_sale(date_sale), price(price), sale(sale), price_with_sale(price*(100-sale)/100) {}

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
string FLAT::getAddressStr(){
    return address.get_string();
}
ADDRESS FLAT::getAddress(){
    return address;
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
string FLAT::getDateSaleStr(){
    return date_sale.get_string();
}
DATE FLAT::getDateSale(){
    return date_sale;
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


ostream& operator<<(ostream& os, const FLAT& obj){
    os<<obj.number<<' '<<obj.address<<' '<<obj.square<<' '<<obj.floor<<' '<<obj.side<<' ';
    os<<obj.date_sale<<' '<<obj.price<<' '<<obj.sale<<' '<<obj.price_with_sale<<endl;
    return os;
}

void FLAT::printShortInfo(){
    cout<<number<<' '<<address.get_string()<<' '<<square<<endl;
}