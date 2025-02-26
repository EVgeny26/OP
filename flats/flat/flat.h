#ifndef FLAT_H
#define FLAT_H

#include <iostream>
#include <string>
#include "structs.h"

#endif

using namespace std;

class FLAT{
protected:
    unsigned int number;//?
    ADDRESS address;//const
    unsigned short square;//?
    unsigned short floor;//const
    SIDE side;//?
    DATA data_sale;//const
    unsigned int price;//change

    SALE sale;//change
    unsigned int price_with_sale;

public:
    FLAT(unsigned int number, ADDRESS address, unsigned short square, unsigned short floor, SIDE side, DATA data_sale, unsigned int price, SALE sale);
    ~FLAT();

    void setPrice(unsigned int newPrice);
    void setSale(SALE sale);

    unsigned int getNumder();
    string getAddress();
    unsigned int getSquare();
    unsigned int getFloor();
    int getSide();
    string getDataSale();
    unsigned int getPrice();
    int getSale();
    unsigned int getPriceWithSale();
    friend ostream& operator<<(ostream& os, const FLAT& s);
    void printShortInfo();


};