#include "flat.h"


FLAT::FLAT(){}

FLAT::FLAT(unsigned int number, ADDRESS address, unsigned short square, unsigned short floor, SIDE side, DATE date_sale, unsigned int price, SALE sale):
    number(number), address(address), square(square), floor(floor), side(side), date_sale(date_sale), price(price), sale(sale), price_with_sale(price*(100-sale)/100) {}

FLAT::FLAT(unsigned int number, string region, string city, string street, unsigned short num_street, unsigned short num_flat, unsigned short square, unsigned short floor, int sideIndex, unsigned short year, unsigned short month, unsigned short day, unsigned int price, int sale): number(number), square(square), floor(floor), side(SIDE(sideIndex)), sale(SALE(sale)), price(price), price_with_sale(price*(100-sale)/100){
    ADDRESS address;
    address.region = region;
    address.city = city;
    address.street = street;
    address.num_street = num_street;
    address.num_flat = num_flat;
    this->address = address;

    DATE date;
    date.day = day;
    date.month = month;
    date.year = year;
    this->date_sale = date;
}

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

string FLAT::operator[](int pos){
    switch(pos){
        case 0: 
            return to_string(number);
            break;
        case 1: 
            return address.get_string();
            break;
        case 2: 
            return to_string(square);
            break;
        case 3: 
            return to_string(floor);
            break;
        case 4: 
            return to_string(side);
            break;
        case 5: 
            return date_sale.get_string();
            break;
        case 6: 
            return to_string(price);
            break;
        case 7: 
            return to_string(sale);
            break;
        case 8: 
            return to_string(price_with_sale);
            break;
        default:
            throw out_of_range("Индекс за пределами диапазона");
            break;
    }
}