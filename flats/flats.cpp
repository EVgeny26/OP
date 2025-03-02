#include "flats.h"
#include <stdexcept>
#include <fstream>


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


void LIST_FLAT::getFlatsForData(DATE date){
    ELEM *current_flat=head;
    ELEM* previos = nullptr;
    for(int i = 0; i < lenght; i++){
        if(current_flat->flat.getDataSale() == date.get_string()) cout << current_flat->flat;
        previos=current_flat;
        current_flat=current_flat->next_el;
    }
}

void LIST_FLAT::getFlatsForMonthAndSide(unsigned short month, unsigned short year){
    ELEM *current_flat=head;
    ELEM* previos = nullptr;
    FLAT flat = current_flat->flat;
    DATE date = flat.getDate();
    SIDE side = SIDE(YARD);
    for(int i = 0; i < lenght; i++){
        flat = current_flat->flat;
        date = flat.getDate();
        if(date.month == month && date.year == year && flat.getSide() == side) cout << flat;
        previos=current_flat;
        current_flat=current_flat->next_el;
    }
}

void LIST_FLAT::getFlatsForFirstHalfYear(unsigned short year){
    ELEM *current_flat=head;
    ELEM* previos = nullptr;
    FLAT flat = current_flat->flat;
    DATE date = flat.getDate();
    for(int i = 0; i < lenght; i++){
        flat = current_flat->flat;
        date = flat.getDate();
        if(date.month > 0 && date.month < 7 && date.year == year) cout << flat;
        previos=current_flat;
        current_flat=current_flat->next_el;
    }
}

short LIST_FLAT::getFlatsForMonthAndPrice(unsigned short month, unsigned short year, unsigned int price, char sign){
    ELEM *current_flat=head;
    ELEM* previos = nullptr;
    FLAT flat = current_flat->flat;
    DATE date = flat.getDate();
    int count = 0;
    for(int i = 0; i < lenght; i++){
        flat = current_flat->flat;
        date = flat.getDate();
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
        previos=current_flat;
        current_flat=current_flat->next_el;
    }
    float percent = (count*(1.0) / lenght);
    return short(percent * 100);
}


void LIST_FLAT::getFlatsWithSale(){
    ELEM *current_flat=head;
    ELEM* previos = nullptr;
    FLAT flat = current_flat->flat;
    SALE sale = SALE(FOR_WORKERS);
    for(int i = 0; i < lenght; i++){
        flat = current_flat->flat;
        if(flat.getSale() == sale) cout << flat;
        previos=current_flat;
        current_flat=current_flat->next_el;
    }
}

void LIST_FLAT::getFlatsWithSaleOnFloor(unsigned short floor){
    ELEM *current_flat=head;
    ELEM* previos = nullptr;
    FLAT flat = current_flat->flat;
    SALE sale = SALE(FOR_WORKERS);
    for(int i = 0; i < lenght; i++){
        flat = current_flat->flat;
        if(flat.getSale() == sale && flat.getFloor() == floor) cout << flat;
        previos=current_flat;
        current_flat=current_flat->next_el;
    }
}

short LIST_FLAT::getPersentSaleFromFlatForMonth(unsigned short month, unsigned short year){
    ELEM *current_flat=head;
    ELEM* previos = nullptr;
    FLAT flat = current_flat->flat;
    DATE date = flat.getDate();
    SALE sale = SALE(FOR_WORKERS);
    int sumSale = 0;
    int sumDiscount = 0;
    for(int i = 0; i < lenght; i++){
        flat = current_flat->flat;
        date = flat.getDate();
        sumSale += flat.getPrice();
        if(date.month == month && date.year == year && flat.getSale() == sale){
            sumDiscount += (flat.getPrice() -  flat.getPriceWithSale());
        }
        previos=current_flat;
        current_flat=current_flat->next_el;
    }
    short percent = (sumDiscount * (1.0) / sumSale) * 100;
    return percent;
}



void LIST_FLAT::saveToFile(){
    string fileName = "file.bin";
    ofstream file(fileName, ios::out | ios::binary);
    if(!file){
        cerr << "Ошибка! Файл не существует!\n";
        return;
    }
    ELEM *current_flat=head;
    ELEM* previos = nullptr;
    FLAT flat = current_flat->flat;
    for(int i = 0; i < lenght; i++){
        flat = current_flat->flat;
        // cout << flat.getNumder() << endl;
        // file<<flat.getNumder()<<' '<<flat.getAddress()<<' '<<flat.getSquare()<<' '<<flat.getFloor()<<' '<<flat.getSide()<<' '<<flat.getDataSale()<<' '<<flat.getPrice()<<' '<<flat.getSale()<<' '<<flat.getPriceWithSale()<<endl;
        file.write((char *) &flat, sizeof(FLAT));
        previos=current_flat;
        current_flat=current_flat->next_el;
    }
    file.close();
}


// void LIST_FLAT::loadFromFile(){
//     string fileName = "file.bin";
//     ifstream file(fileName, ios::in | ios::binary);
//     FLAT flat = FLAT();
//     if(!file){
//         cerr << "Ошибка! Файл не существует!\n";
//         return;
//     }
//     while(file.read((char *)&flat, sizeof(FLAT))){
//         cout << sizeof(FLAT) << endl;
//         addFlat(flat);
//         cout << lenght << endl;
//     }
//     file.close();
// }