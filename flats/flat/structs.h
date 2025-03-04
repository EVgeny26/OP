#ifndef STRUCT_H
#define STRUCT_H

#include <iostream>
#include <string>

#endif

using namespace std;

struct DATE
{
    unsigned short year{2000};
    unsigned short month{1};
    unsigned short day{1};


    string get_string();
    bool operator==(const DATE& other) const;
    bool operator!=(const DATE& other) const;
    bool operator<(const DATE& other) const;
    bool operator>(const DATE& other) const;
    bool operator<=(const DATE& other) const;
    bool operator>=(const DATE& other) const;
    //DATE operator+(unsigned short days) const;
    void setDate();
};
ostream& operator<<(ostream& os, const DATE date);

struct ADDRESS
{
    string region = " ";
    string city = " ";
    string street = " ";
    unsigned short num_street{};
    unsigned short num_flat{};

    string get_string();
    bool operator==(const ADDRESS& other) const;
    bool operator!=(const ADDRESS& other) const;
    bool operator<(const ADDRESS& other) const;
    bool operator>(const ADDRESS& other) const;
    bool operator<=(const ADDRESS& other) const;
    bool operator>=(const ADDRESS& other) const;
    void setAddress();
};
ostream& operator<<(ostream& os, const ADDRESS address);


enum SIDE{
    YARD = 0, STREET = 1, 
    //FOREST, SEA, RIVER, LAKE, 
};
enum SALE{
    NOT=0, FOR_WORKERS=30, 
};