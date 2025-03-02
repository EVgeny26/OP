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
    flats->addFlat(FLAT{++number, address, ++square, ++floor, side, date_sale, ++price, SALE(FOR_WORKERS)});
    flats->addFlat(FLAT{++number, address, ++square, ++floor, side, date_sale, ++price, sale});
    cout<<flats->getLenght()<<" len prelast"<<endl;


    flats->printAll();
    cout<<endl;
    for(int i=0;i<flats->getLenght(); i++) cout<<(*flats)[i];
    cout << "getFlatsForData\n";
    flats->getFlatsForData(date_sale);
    cout << "getFlatsForMonthAndSide\n";
    flats->getFlatsForMonthAndSide(date_sale.month, date_sale.year);
    cout << "getFlatsForFirstHalfYear\n";
    flats->getFlatsForFirstHalfYear(date_sale.year);
    cout << "getFlatsForMonthAndPrice\n";
    cout << flats->getFlatsForMonthAndPrice(date_sale.month, date_sale.year, price, '=') << endl;
    cout << "getFlatsWithSale\n";
    flats->getFlatsWithSale();
    cout << "getFlatsWithSaleOnFloor\n";
    flats->getFlatsWithSaleOnFloor(3);
    cout << "getPersentSaleFromFlatForMonth\n";
    cout << flats->getPersentSaleFromFlatForMonth(date_sale.month, date_sale.year) << endl;
    delete flats;

    return 0;
}