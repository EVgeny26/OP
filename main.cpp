#ifndef EXAMPLE_H
#define EXAMPLE_H

#include <iostream>
#include <string>
#include "flats/flats.h"

//Test git push ++
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



    LIST_FLAT *flats = new LIST_FLAT{};

    cout<<flats->getLenght();
    flats->delFlatNum(0);
    flats->addFlat(FLAT{number, address, square, floor, side, data_sale, price, sale});
    cout<<flats->getLenght()<<endl;
    flats->addFlat(FLAT{++number, address, ++square, ++floor, side, data_sale, ++price, sale});
    flats->addFlat(FLAT{++number, address, ++square, ++floor, side, data_sale, ++price, sale});
    flats->addFlat(FLAT{++number, address, ++square, ++floor, side, data_sale, ++price, sale});
    flats->addFlat(FLAT{++number, address, ++square, ++floor, side, data_sale, ++price, sale});
    cout<<flats->getLenght()<<" len prelast"<<endl;
    flats->printAll();
    cout<<endl;

    flats->delFlatNum(0);
    flats->delFlatNum(0);
    flats->printAll();
    cout<<endl;

    flats->delFlatNum(3);
    flats->printAll();
    cout<<endl;

    // flats->getFlatNum(0)->print();


    delete flats;



    return 0;
}