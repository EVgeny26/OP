#ifndef EXAMPLE_H
#define EXAMPLE_H

#include <iostream>
#include <string>
#include "flats/flat.h"

#endif

using namespace std;





int main(){
    unsigned int number{};
    ADDRESS address{};
    unsigned short square{};
    unsigned short floor{};
    SIDE side{};
    DATA data_sale{};
    unsigned int price{};
    SALE sale{};

    FLAT flats{number, address, square, floor, side, data_sale, price, sale};
    

    return 0;
}