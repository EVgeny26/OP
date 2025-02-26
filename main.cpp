#ifndef EXAMPLE_H
#define EXAMPLE_H

#include <iostream>
#include <string>
#include "flats/flats.h"

//Test git push ++++

#endif

using namespace std;


int main(){
    unsigned int number{};
    ADDRESS address{};
    unsigned short square{};
    unsigned short floor{};
    SIDE side{};
    DATE date_sale{};
    unsigned int price{};
    SALE sale{};

    LIST_FLAT *flats = new LIST_FLAT{};

    flats->addFlat(FLAT{number, address, square, floor, side, date_sale, price, sale});
    flats->addFlat(FLAT{++number, address, ++square, ++floor, side, date_sale, ++price, sale});
    flats->addFlat(FLAT{++number, address, ++square, ++floor, side, date_sale, ++price, sale});
    flats->addFlat(FLAT{++number, address, ++square, ++floor, side, date_sale, ++price, sale});
    flats->addFlat(FLAT{++number, address, ++square, ++floor, side, date_sale, ++price, sale});
    cout<<flats->getLenght()<<" len prelast"<<endl;


    flats->printAll();
    cout<<endl;
    for(int i=0;i<flats->getLenght(); i++) cout<<(*flats)[i];


    delete flats;

    return 0;
}