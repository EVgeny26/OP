#include <iostream>
#include <string>


using namespace std;

struct ADDRESS
{
    string region{};
    string city{};
    string street{};
    unsigned short num_street{};
    unsigned short num_flat{};

    void print();
    string get_string();
    bool operator==(const ADDRESS& other) const;
    bool operator!=(const ADDRESS& other) const;
};

struct DATA
{
    unsigned short year{2000};
    unsigned short month{1};
    unsigned short day{1};

    void print();
    string get_string();
    bool operator==(const DATA& other) const;
    bool operator!=(const DATA& other) const;
};


enum SIDE{
    YARD, STREET, 
    //FOREST, SEA, RIVER, LAKE, 
};
enum SALE{
    NOT=0, FOR_WORKERS=30, 
};