#ifndef LISTS_H
#define LISTS_H

#include "flat/flat.h"

class LIST_FLAT{
    Vector<FLAT> flats;

public:
    LIST_FLAT();
    ~LIST_FLAT();
    unsigned int getLenght();
    void addFlat(FLAT newFlat);
    void printAll();
    //FLAT& getFlatNum(int pos);
    FLAT& operator[](int pos);
    void delFlatNum(int pos);
    void sorted(unsigned short pole, bool revers);

    //реализовать
    //работа с файлами
    void loadFromFile(string fileName);
    void saveToFile(string fileName);


    //запросы
    Vector<FLAT> getFlatsForData(DATE date); //you can DATE==DATE
    Vector<FLAT> getFlatsForMonthAndSide(unsigned short month, unsigned short year, SIDE side);
    Vector<FLAT> getFlatsForFirstHalfYear(unsigned short year);
    short getFlatsForMonthAndPrice(unsigned short month, unsigned short year, unsigned int price, char sign);

    Vector<FLAT> getFlatsWithSale();
    Vector<FLAT> getFlatsWithSaleOnFloor(unsigned short floor);
    short getPersentSaleFromFlatForMonth(unsigned short month, unsigned short year);

};

#endif //LISTS_H