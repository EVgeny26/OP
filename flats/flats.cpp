#include "flats.h"
#include <stdexcept>
#include <fstream>
#include <sstream>
#include <cstring>


LIST_FLAT::LIST_FLAT(): flats() {}

LIST_FLAT::~LIST_FLAT(){}

unsigned int LIST_FLAT::getLenght(){
    return flats.size();
}

void LIST_FLAT::addFlat(FLAT newFlat){
    flats.push_back(newFlat);
}

void LIST_FLAT::printAll(){
    cout<<"№    Адресс    площадь     Этаж   Сторона  Дата продажи     Цена   Скидка    Цена со скидкой"<<endl;
    for(auto flat : flats){
        cout<<flat;
    }
}


FLAT& LIST_FLAT::operator[](int pos){
    return flats[pos];
}

void LIST_FLAT::sorted(unsigned short pole=0, bool revers=0){
    bool isChangee{};
    size_t lenght=flats.size();
    for (int i = 0; i < lenght; i++) {
        for (int j = 0; j < lenght - i-1; j++) {
            switch (pole){
                case 0: case 1:
                    isChangee=(*this)[j].getNumder()>(*this)[j+1].getNumder();
                    break;
                case 2:
                    isChangee=(*this)[j].getAddressStr()>(*this)[j+1].getAddressStr();
                    break;
                case 3:
                    isChangee=(*this)[j].getSquare()>(*this)[j+1].getSquare();
                    break;
                case 4:
                    isChangee=(*this)[j].getFloor()>(*this)[j+1].getFloor();
                    break;
                case 5:
                    isChangee=(*this)[j].getDateSaleStr()>(*this)[j+1].getDateSaleStr();
                    break;
                case 6:
                    isChangee=(*this)[j].getPrice()>(*this)[j+1].getPrice();
                    break;
                default:
                    return;
            }
            if (revers)isChangee-=1;
            if (isChangee) {
                FLAT temp = (*this)[j];
                (*this)[j] = (*this)[j + 1];
                (*this)[j + 1] = temp;
            }
        }
    }
}


void LIST_FLAT::delFlatNum(int pos){
    flats.erase(flats.begin()+pos);
}

void LIST_FLAT::saveToFile(){
    string fileName = "file.txt";
    ofstream file(fileName, ios::out);
    if(!file){
        cerr << "Ошибка! Файл не существует!\n";
        return;
    }
    for(auto flat : flats){
        file<<flat.getNumder()<<'|'<<flat.getAddress().get_string()<<'|'<<flat.getSquare()<<'|'<<flat.getFloor()<<'|'<<flat.getSide()<<'|'<<flat.getDateSaleStr()<<'|'<<flat.getPrice()<<'|'<<flat.getSale()<<'|'<<flat.getPriceWithSale()<<endl;
    }
    file.close();
}

ADDRESS parseAddress(const string& adr) {
    ADDRESS address;
    istringstream addressStream(adr);
    string token;

    getline(addressStream, address.region, ' ');
    getline(addressStream, address.city, ' ');
    getline(addressStream, address.street, ' ');
    getline(addressStream, token, ' ');
    address.num_street = stoi(token);
    getline(addressStream, token, ' ');
    address.num_flat = stoi(token);

    return address;
}
DATE parseDate(const string& dateStr) {
    DATE date;
    istringstream dateStream(dateStr);
    string token;

    getline(dateStream, token, '.');
    date.day = stoi(token);
    getline(dateStream, token, '.');
    date.month = stoi(token);
    getline(dateStream, token, '.');
    date.year = stoi(token);

    return date;
}

void LIST_FLAT::loadFromFile(){
    string fileName = "file.txt";
    ifstream file(fileName, ios::in);
    if(!file){
        cerr << "Ошибка! Файл не существует!\n";
        return;
    }
    unsigned int number{};
    ADDRESS address{};
    unsigned short square{};
    unsigned short floor{};
    SIDE side{};
    DATE date_sale{};
    unsigned int price{};
    SALE sale{};
    string token = "";
    string line = "";
    FLAT flat = FLAT();
    while(getline(file, line)){
        istringstream iss(line);
        getline(iss, token, '|');
        number = stoi(token);
        getline(iss, token, '|');
        address = parseAddress(token);
        getline(iss, token, '|');
        square = stoi(token);
        getline(iss, token, '|');
        floor = stoi(token);
        getline(iss, token, '|');
        side = SIDE(stoi(token));
        getline(iss, token, '|');
        date_sale = parseDate(token);
        getline(iss, token, '|');
        price = stoi(token);
        getline(iss, token, '|');
        sale = SALE(stoi(token));
        flat = FLAT(number, address, square, floor, side, date_sale, price, sale);
        addFlat(flat);
    }
    file.close();
}



Vector<FLAT> LIST_FLAT::getFlatsForData(DATE date){
    Vector<FLAT> requestFlats;
    for(auto flat : flats){
        if(flat.getDateSaleStr() == date.get_string()){
            requestFlats.push_back(flat);
        }
    }return requestFlats;
}

Vector<FLAT> LIST_FLAT::getFlatsForMonthAndSide(unsigned short month, unsigned short year, SIDE side){
    Vector<FLAT> requestFlats;
    for(auto flat : flats){
        DATE date = flat.getDateSale();
        if(date.month == month && date.year == year && flat.getSide() == side) 
            requestFlats.push_back(flat);
    }return requestFlats;
}

Vector<FLAT> LIST_FLAT::getFlatsForFirstHalfYear(unsigned short year){
    Vector<FLAT> requestFlats;
    for(auto flat : flats){
        DATE date = flat.getDateSale();
        if(date.month > 0 && date.month < 7 && date.year == year)
            requestFlats.push_back(flat);
    }return requestFlats;
}


// need some changes
short LIST_FLAT::getFlatsForMonthAndPrice(unsigned short month, unsigned short year, unsigned int price, char sign){
    int count = 0;
    for(auto flat : flats){
        DATE date = flat.getDateSale();
        if(date.month == month && date.year == year){
            if(sign == '=' && flat.getPrice() == price || sign == '>' && flat.getPrice() > price || sign == '<' && flat.getPrice() < price){
                count++;
            }
        }
    }
    float percent = (count*(1.0) / flats.size());
    return short(percent * 100);
}


Vector<FLAT> LIST_FLAT::getFlatsWithSale(){
    Vector<FLAT> requestFlats;
    SALE sale = SALE(FOR_WORKERS);
    for(auto flat : flats){
        if(flat.getSale() == sale) 
        requestFlats.push_back(flat);
    }return requestFlats;
}

Vector<FLAT> LIST_FLAT::getFlatsWithSaleOnFloor(unsigned short floor){
    Vector<FLAT> requestFlats;
    SALE sale = SALE(FOR_WORKERS);
    for(auto flat : flats){
        if(flat.getSale() == sale && flat.getFloor() == floor)
            requestFlats.push_back(flat);
    }return requestFlats;
}

short LIST_FLAT::getPersentSaleFromFlatForMonth(unsigned short month, unsigned short year){
    SALE sale = SALE(FOR_WORKERS);
    int sumSale = 0;
    int sumDiscount = 0;
    for(auto flat : flats){
        DATE date = flat.getDateSale();
        sumSale += flat.getPrice();
        if(date.month == month && date.year == year && flat.getSale() == sale){
            sumDiscount += (flat.getPrice() -  flat.getPriceWithSale());
        }
    }
    short percent = (sumDiscount * (1.0) / sumSale) * 100;
    return percent;
}
