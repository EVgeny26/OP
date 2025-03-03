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
    // flats->loadFromFile();

    flats->addFlat(FLAT{number, address, square, floor, side, date_sale, price, sale});
<<<<<<< HEAD
    flats->addFlat(FLAT{++number, address, ++square, ++floor, side, date_sale, 9, sale});
    flats->addFlat(FLAT{++number, address, ++square, ++floor, side, date_sale, 5, sale});
    flats->addFlat(FLAT{++number, address, ++square, ++floor, side, date_sale, 3, SALE(FOR_WORKERS)});
    flats->addFlat(FLAT{++number, address, ++square, ++floor, side, date_sale, 8, sale});
=======
    flats->addFlat(FLAT{++number, address, ++square, ++floor, side, date_sale, ++price, sale});
    flats->addFlat(FLAT{++number, address, ++square, ++floor, side, date_sale, ++price, sale});
    flats->addFlat(FLAT{++number, address, ++square, ++floor, side, date_sale, ++price, SALE(FOR_WORKERS)});
    flats->addFlat(FLAT{++number, address, ++square, ++floor, side, date_sale, ++price, sale});
>>>>>>> a422b3aeb7fea2ac8d27b42a3e21bf01057f812f
    cout<<flats->getLenght()<<" len prelast"<<endl;


    flats->printAll();
<<<<<<< HEAD
    // cout<<endl;
    // for(int i=0;i<flats->getLenght(); i++) cout<<(*flats)[i];
    // cout << "getFlatsForData\n";
    // flats->getFlatsForData(date_sale);
    // cout << "getFlatsForMonthAndSide\n";
    // flats->getFlatsForMonthAndSide(date_sale.month, date_sale.year);
    // cout << "getFlatsForFirstHalfYear\n";
    // flats->getFlatsForFirstHalfYear(date_sale.year);
    // cout << "getFlatsForMonthAndPrice\n";
    // cout << flats->getFlatsForMonthAndPrice(date_sale.month, date_sale.year, price, '=') << endl;
    // cout << "getFlatsWithSale\n";
    // flats->getFlatsWithSale();
    // cout << "getFlatsWithSaleOnFloor\n";
    // flats->getFlatsWithSaleOnFloor(3);
    // cout << "getPersentSaleFromFlatForMonth\n";
    // cout << flats->getPersentSaleFromFlatForMonth(date_sale.month, date_sale.year) << endl;
    
    // flats->saveToFile();

    FLAT temp = (*flats)[2];
    (*flats)[2] = (*flats)[2 + 1];
    (*flats)[2 + 1] = temp;
=======
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
    
    flats->saveToFile();
>>>>>>> a422b3aeb7fea2ac8d27b42a3e21bf01057f812f

    cout<<endl<<endl;
    flats->printAll();

    flats->sorted(6,1);

    cout<<endl<<endl;
    flats->printAll();
    delete flats;

    return 0;
}