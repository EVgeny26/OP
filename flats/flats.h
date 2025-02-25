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
    FLAT getFlatNum(int pos);
    void delFlatNum(int pos);


};