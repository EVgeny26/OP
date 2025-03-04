#ifndef EXAMPLE_H
#define EXAMPLE_H

#include <iostream>
#include <string>
#include "flats/flats.h"

//Test git push ++++

#endif

using namespace std;


int main(){
    unsigned int number{};
    ADDRESS address{};
    unsigned short square{};
    unsigned short floor{};
    SIDE side{};
    DATE date_sale{};
    unsigned int price{};
    SALE sale{};
    LIST_FLAT *flats = new LIST_FLAT{};


    int sw = 0, num = 0;
    FLAT flat = FLAT();
    number = flats->getLenght();
    do{
        cout << "\n\nМЕНЮ\n";
        cout << "1. Добавить\n2. Удалить\n3. Сортировать\n4. Распечатать данные\n5. Запросы\n6. Сохранить в файл\n7. Загрузить из файла\n0. Выход: ";
        cin >> sw;
        switch (sw)
        {
        case 0:
            break;
        case 1:
            number++;
            address.setAddress();
            cout << "Введите площадь: ";
            cin >> square;
            cout << "Введите этаж: ";
            cin >> floor;
            cout << "Выберите куда выходят окна: \nВо двор - 0\nНа улицу - 1\n";
            cin >> num;
            side = SIDE(num);
            date_sale.setDate();
            cout << "Введите цену: ";
            cin >> price;
            cout << "Введите сумму скидки:\nNOT - 0\nFOR_WORKERS - 30\n";
            cin >> num;
            sale = SALE(num);
            flat = FLAT(number, address, square, floor, side, date_sale, price, sale);
            flats->addFlat(flat);
            break;
        case 4:
            flats->printAll();
            break;
        case 6:
            flats->saveToFile();
            break;
        case 7:
            flats->loadFromFile();
            break;
        default:
            break;
        }
    }while(sw);

    // flats->loadFromFile();

    // flats->addFlat(FLAT{number, address, square, floor, side, date_sale, price, sale});
    // flats->addFlat(FLAT{++number, address, ++square, ++floor, side, date_sale, 9, sale});
    // flats->addFlat(FLAT{++number, address, ++square, ++floor, side, date_sale, 5, sale});
    // flats->addFlat(FLAT{++number, address, ++square, ++floor, side, date_sale, 3, SALE(FOR_WORKERS)});
    // flats->addFlat(FLAT{++number, address, ++square, ++floor, side, date_sale, 8, sale});

    // cout<<flats->getLenght()<<" len prelast"<<endl;


    // flats->printAll();

    // cout<<endl;
    // for(int i=0;i<flats->getLenght(); i++) cout<<(*flats)[i];
    // cout << "getFlatsForData\n";
    // flats->getFlatsForData(date_sale);
    // cout << "getFlatsForMonthAndSide\n";
    // flats->getFlatsForMonthAndSide(date_sale.month, date_sale.year);
    // cout << "getFlatsForFirstHalfYear\n";
    // flats->getFlatsForFirstHalfYear(date_sale.year);
    // cout << "getFlatsForMonthAndPrice\n";
    // cout << flats->getFlatsForMonthAndPrice(date_sale.month, date_sale.year, price, '=') << endl;
    // cout << "getFlatsWithSale\n";
    // flats->getFlatsWithSale();
    // cout << "getFlatsWithSaleOnFloor\n";
    // flats->getFlatsWithSaleOnFloor(3);
    // cout << "getPersentSaleFromFlatForMonth\n";
    // cout << flats->getPersentSaleFromFlatForMonth(date_sale.month, date_sale.year) << endl;
    
    // flats->saveToFile();

    // flats->printAll();



    // FLAT temp = (*flats)[2];
    // (*flats)[2] = (*flats)[2 + 1];
    // (*flats)[2 + 1] = temp;

    // cout<<endl<<endl;
    // flats->printAll();

    // flats->sorted(6,1);

    // cout<<endl<<endl;
    // flats->printAll();
    delete flats;

    return 0;
}