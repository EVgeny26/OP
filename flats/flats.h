#include "flat/flat.h"

class LIST_FLAT{
    struct ELEM
    {
        FLAT flat;
        ELEM* next_el{};
    };
    ELEM* head;
    unsigned int lenght;

public:
    LIST_FLAT();
    ~LIST_FLAT();
    unsigned int getLenght();
    void addFlat(FLAT newFlat);
    void printAll();
    FLAT* getFlatNum(int pos);
    FLAT* operator[](int pos);
    void delFlatNum(int pos);

    //реализовать
    //работа с файлами
    void loudToFile();
    void loudFromFile();


    //запросы
    void getFlatsForData(DATA data); //you can DATA==DATA
    void getFlatsForMonthAndSide(unsigned short month, unsigned short year, SIDE side);
    void getFlatsForFirstHalfYear(unsigned short year);
    void getFlatsForMonthAndPrice(unsigned short month, unsigned short year, unsigned int price, char sign);

    void getFlatsWithSale();
    void getFlatsWithSaleOnFloor(unsigned short floor);
    float getPersentSaleFromFlatForMonth(unsigned short month, unsigned short year);

};