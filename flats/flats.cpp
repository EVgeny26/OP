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
                    isChangee=(*this)[j].getDataSaleStr()>(*this)[j+1].getDataSaleStr();
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