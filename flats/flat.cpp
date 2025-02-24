#include "flat.h"

FLAT::FLAT(unsigned int number, ADDRESS address, unsigned short square, unsigned short floor, SIDE side, DATA data_sale, unsigned int price, SALE sale):
    number(number), address(address), square(square), floor(floor), side(side), data_sale(data_sale), price(price), sale(sale), price_with_sale(price*(100-sale)/100) {}

FLAT::~FLAT(){}



void FLAT::setPrice(unsigned int newPrice){

}
void FLAT::setSale(SALE sale){

}



void FLAT::getNumder(){

}
void FLAT::getAddress(){

}
void FLAT::getSquare(){

}
void FLAT::getFloor(){

}
void FLAT::getSide(){

}
void FLAT::getDataSale(){

}
void FLAT::getPrice(){

}
void FLAT::getSale(){

}
void FLAT::getPriceWithSale(){

}