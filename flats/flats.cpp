#include "flats.h"

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
        current_flat->flat.print();
        current_flat=current_flat->next_el;
    }
}

FLAT* LIST_FLAT::getFlatNum(int pos){      //????????????????????????????
    if(lenght<=pos){
        cout<<"Out of range\n";
        return nullptr;
    }ELEM *current_flat=head;
    for(int i=0;i<pos;i++)current_flat=current_flat->next_el;
    return &current_flat->flat;
}

void LIST_FLAT::delFlatNum(int pos){
    if(lenght<=pos){
        cout<<"Out of range\n";
        return;
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