#ifndef FLAT_H
#define FLAT_H

#include <iostream>
#include <string>
#include "structs.h"

#endif

using namespace std;

class FLAT{
protected:
    unsigned int number;//? //s1
    ADDRESS address;//const //s2
    unsigned short square;//? //s3
    unsigned short floor;//const //s4
    SIDE side;//?
    DATE date_sale;//const //s5
    unsigned int price;//change //s6

    SALE sale;//change
    unsigned int price_with_sale;

public:
    FLAT();
    FLAT(unsigned int number, ADDRESS address, unsigned short square, unsigned short floor, SIDE side, DATE date_sale, unsigned int price, SALE sale);
    ~FLAT();

    void setPrice(unsigned int newPrice);
    void setSale(SALE sale);

    unsigned int getNumder();
    string getAddressStr();
    ADDRESS getAddress();
    unsigned int getSquare();
    unsigned int getFloor();
    int getSide();
    string getDataSaleStr();
    DATE getDateSale();
    unsigned int getPrice();
    int getSale();
    unsigned int getPriceWithSale();
    friend ostream& operator<<(ostream& os, const FLAT& s);
    void printShortInfo();


};