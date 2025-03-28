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
    //FLAT& getFlatNum(int pos);
    FLAT& operator[](int pos);
    void delFlatNum(int pos);
    void sorted(unsigned short pole, bool revers);

    //реализовать
    //работа с файлами
    void loadFromFile();
    void saveToFile();


    //запросы
    void getFlatsForData(DATE date); //you can DATE==DATE
    void getFlatsForMonthAndSide(unsigned short month, unsigned short year, SIDE side);
    void getFlatsForFirstHalfYear(unsigned short year);
    short getFlatsForMonthAndPrice(unsigned short month, unsigned short year, unsigned int price, char sign);

    void getFlatsWithSale();
    void getFlatsWithSaleOnFloor(unsigned short floor);
    short getPersentSaleFromFlatForMonth(unsigned short month, unsigned short year);

};