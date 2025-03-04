#include "flats.h"
#include <stdexcept>
#include <fstream>
#include <sstream>
#include <cstring>


LIST_FLAT::LIST_FLAT(): head(nullptr), lenght(0) {}

LIST_FLAT::~LIST_FLAT(){
    ELEM* current = head;
    while (current != nullptr) {
        ELEM* next = current->next_el;
        delete current;
        current = next;
    }
}

unsigned int LIST_FLAT::getLenght(){
    return lenght;
}

void LIST_FLAT::addFlat(FLAT newFlat){
    ELEM *flat = new ELEM{newFlat};
    if(head == nullptr){
        head=flat;
    }else{
        ELEM *temp=head;
        while(temp->next_el!=nullptr)temp=temp->next_el;
        temp->next_el=flat;
    }
    lenght++;
}

void LIST_FLAT::printAll(){
    ELEM *current_flat=head;
    while(current_flat!=nullptr){
        cout<<current_flat->flat;
        current_flat=current_flat->next_el;
    }
}

// FLAT& LIST_FLAT::getFlatNum(int pos){
//     if(lenght<=pos){
//         throw std::out_of_range("Индекс за пределами диапазона");
//     }ELEM *current_flat=head;
//     for(int i=0;i<pos;i++)current_flat=current_flat->next_el;
//     return current_flat->flat;
// }

FLAT& LIST_FLAT::operator[](int pos){
    if(lenght<=pos){
        throw std::out_of_range("Индекс за пределами диапазона");
    }ELEM *current_flat=head;
    for(int i=0;i<pos;i++)current_flat=current_flat->next_el;
    return current_flat->flat;
}

void LIST_FLAT::sorted(unsigned short pole=0, bool revers=0){
    bool isChangee{};
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
    if(lenght<=pos){
        throw std::out_of_range("Индекс за пределами диапазона");
    }
    ELEM *current_flat=head;
    ELEM* previos = nullptr;
    for(int i=0;i<pos;i++){
        previos=current_flat;
        current_flat=current_flat->next_el;
    }
    if(previos==nullptr) head=current_flat->next_el;
    else previos->next_el=current_flat->next_el;
    delete current_flat;
    lenght--;
}

void LIST_FLAT::saveToFile(){
    string fileName = "file.txt";
    ofstream file(fileName, ios::out);
    if(!file){
        cerr << "Ошибка! Файл не существует!\n";
        return;
    }
    ELEM *current_flat=head;
    FLAT flat = current_flat->flat;
    for(int i = 0; i < lenght; i++){
        flat = current_flat->flat;
        file<<flat.getNumder()<<'|'<<flat.getAddress().get_string()<<'|'<<flat.getSquare()<<'|'<<flat.getFloor()<<'|'<<flat.getSide()<<'|'<<flat.getDateSaleStr()<<'|'<<flat.getPrice()<<'|'<<flat.getSale()<<'|'<<flat.getPriceWithSale()<<endl;
        current_flat=current_flat->next_el;
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



void LIST_FLAT::getFlatsForData(DATE date){
    ELEM *current_flat=head;
    for(int i = 0; i < lenght; i++){
        if(current_flat->flat.getDateSaleStr() == date.get_string()) cout << current_flat->flat;
        current_flat=current_flat->next_el;
    }
}

void LIST_FLAT::getFlatsForMonthAndSide(unsigned short month, unsigned short year){
    ELEM *current_flat=head;
    FLAT flat = current_flat->flat;
    DATE date = flat.getDateSale();
    SIDE side = SIDE(YARD);
    for(int i = 0; i < lenght; i++){
        flat = current_flat->flat;
        date = flat.getDateSale();
        if(date.month == month && date.year == year && flat.getSide() == side) cout << flat;
        current_flat=current_flat->next_el;
    }
}

void LIST_FLAT::getFlatsForFirstHalfYear(unsigned short year){
    ELEM *current_flat=head;
    FLAT flat = current_flat->flat;
    DATE date = flat.getDateSale();
    for(int i = 0; i < lenght; i++){
        flat = current_flat->flat;
        date = flat.getDateSale();
        if(date.month > 0 && date.month < 7 && date.year == year) cout << flat;
        current_flat=current_flat->next_el;
    }
}

short LIST_FLAT::getFlatsForMonthAndPrice(unsigned short month, unsigned short year, unsigned int price, char sign){
    ELEM *current_flat=head;
    FLAT flat = current_flat->flat;
    DATE date = flat.getDateSale();
    int count = 0;
    for(int i = 0; i < lenght; i++){
        flat = current_flat->flat;
        date = flat.getDateSale();
        if(date.month == month && date.year == year){
            if(sign == '=' && flat.getPrice() == price){
                count++;
                cout << flat;
            }else if(sign == '>' && flat.getPrice() > price){
                count++;
                cout << flat;
            }else if(sign == '<' && flat.getPrice() < price){
                count++;
                cout << flat;
            }
        }
        current_flat=current_flat->next_el;
    }
    float percent = (count*(1.0) / lenght);
    return short(percent * 100);
}


void LIST_FLAT::getFlatsWithSale(){
    ELEM *current_flat=head;
    FLAT flat = current_flat->flat;
    SALE sale = SALE(FOR_WORKERS);
    for(int i = 0; i < lenght; i++){
        flat = current_flat->flat;
        if(flat.getSale() == sale) cout << flat;
        current_flat=current_flat->next_el;
    }
}

void LIST_FLAT::getFlatsWithSaleOnFloor(unsigned short floor){
    ELEM *current_flat=head;
    FLAT flat = current_flat->flat;
    SALE sale = SALE(FOR_WORKERS);
    for(int i = 0; i < lenght; i++){
        flat = current_flat->flat;
        if(flat.getSale() == sale && flat.getFloor() == floor) cout << flat;
        current_flat=current_flat->next_el;
    }
}

short LIST_FLAT::getPersentSaleFromFlatForMonth(unsigned short month, unsigned short year){
    ELEM *current_flat=head;
    FLAT flat = current_flat->flat;
    DATE date = flat.getDateSale();
    SALE sale = SALE(FOR_WORKERS);
    int sumSale = 0;
    int sumDiscount = 0;
    for(int i = 0; i < lenght; i++){
        flat = current_flat->flat;
        date = flat.getDateSale();
        sumSale += flat.getPrice();
        if(date.month == month && date.year == year && flat.getSale() == sale){
            sumDiscount += (flat.getPrice() -  flat.getPriceWithSale());
        }
        current_flat=current_flat->next_el;
    }
    short percent = (sumDiscount * (1.0) / sumSale) * 100;
    return percent;
}
