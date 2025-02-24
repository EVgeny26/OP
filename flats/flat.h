#include <iostream>
#include <string>

using namespace std;

class FLAT{
    struct ADDRESS
    {
        string region;
        string city;
        string street;
        unsigned short num_street;
        unsigned short num_flat{};

        void print(){
            cout<<region<<", "<<city<<", ул. "<<street<<" №"<<num_street;
            if(num_flat)cout<<" кв. "<<num_flat;
        }
        string get_string(){
            string address{region+", "+city+", ул. "+street+" №"+to_string(num_street)};
            if(num_flat)address+=" кв. "+to_string(num_flat);
            return address;
        }
    };
    
    struct DATA
    {
        unsigned short year;
        unsigned short month;
        unsigned short day;

        void print(){
            cout<<day<<'.'<<month<<'.'<<year;
        }
        string get_string(){
            string data{to_string(day)+'.'+to_string(month)+'.'+to_string(year)};
            return data;
        }
    };


    enum SIDE{
        SEA, FOREST, RIVER, LAKE, STREET, YARD
    };
    enum SALE{
        NOT=0, FOR_WORKERS=30, 
    };

    unsigned int number;//?
    ADDRESS address;//const
    unsigned short square;//?
    unsigned short floor;//const
    SIDE side;//?
    DATA data_sale;//const
    unsigned int price;//change

    SALE sale;//change
    unsigned int price_with_sale;

public:
    FLAT(unsigned int number, ADDRESS address, unsigned short square, unsigned short floor, SIDE side, DATA data_sale, unsigned int price, SALE sale);
    ~FLAT();

    void setPrice(unsigned int newPrice);
    void setSale(SALE sale);

    void getNumder();
    void getAddress();
    void getSquare();
    void getFloor();
    void getSide();
    void getDataSale();
    void getPrice();
    void getSale();
    void getPriceWithSale();

    


};