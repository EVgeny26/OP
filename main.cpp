#ifndef EXAMPLE_H
#define EXAMPLE_H

#include <iostream>
#include <string>
#include "flats/flats.h"

//Test git push ++++1111

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

    flats->loadFromFile("file.txt");
    flats->printAll();

    for(int i=0;i<9;i++){
        cout<<(*flats)[0][i]<<endl;
    }
    




    // char znak = '=';
    // int pos{}, rev{};
    // int sw = 0, num = 0, zapros = 0, month = 0, year = 0;
    // FLAT flat = FLAT();
    // number = flats->getLenght();
    // do{
    //     cout << "\n\nМЕНЮ\n";
    //     cout << "1. Добавить\n2. Удалить\n3. Сортировать\n4. Распечатать данные\n5. Запросы\n6. Сохранить в файл\n7. Загрузить из файла\n0. Выход\n:";
    //     cin >> sw;
    //     switch (sw)
    //     {
    //     case 0:
    //         break;
    //     case 1:
    //         number++;
    //         address.setAddress();
    //         cout << "Введите площадь: ";
    //         cin >> square;
    //         cout << "Введите этаж: ";
    //         cin >> floor;
    //         cout << "Выберите куда выходят окна: \nВо двор - 0\nНа улицу - 1\n";
    //         cin >> num;
    //         side = SIDE(num);
    //         date_sale.setDate();
    //         cout << "Введите цену: ";
    //         cin >> price;
    //         cout << "Введите сумму скидки:\nNOT - 0\nFOR_WORKERS - 30\n";
    //         cin >> num;
    //         sale = SALE(num);
    //         flat = FLAT(number, address, square, floor, side, date_sale, price, sale);
    //         flats->addFlat(flat);
    //         break;
    //     case 2:
    //         cout << "\nВведите номер квартиры, которую требуется удалить: ";
    //         cin>>pos;
    //         flats->delFlatNum(pos);
    //         break;
    //     case 3:
    //         cout << "\nВведите номер поля, по которому требуется отсортировать: \n";
    //         cout << "1. Номер\n2. Адресс\n3. Площадь\n4. Этаж\n5. Дата продажи\n6. Цена\nВвод: ";
    //         cin>>pos;
    //         cout << "Требуется ли реверс: \n";
    //         cout << "0. Нет\n1. Да\nВвод: ";
    //         cin>>rev;
    //         flats->sorted(pos,rev);
    //         break;
    //     case 4:
    //         flats->printAll();
    //         break;
    //     case 5:
    //         cout << "Выберите запрос:\n";
    //         cout << "1. Вывести список квартир проданных _числа_месяца_года\n";
    //         cout << "2. Вывести список квартир проданных _месяца_года и окна которых выходят на улицу(во двор)\n";
    //         cout << "3. Вывести количество квартир, которые были проданы за первое полугодие _года\n";
    //         cout << "4. Вывести процент от всех проданных квартир за _месяц_года, имели стоимость >,< или = _руб.\n";
    //         cout << "5. Вывести список квартир, имевших скидку при продаже\n";
    //         cout << "6. Вывести количество проданных квартир, которые расположены на_этаже и получившие скидку при продаже\n";
    //         cout << "7. Вывести процент суммы скидки от общей суммы продаж _месяца\n:";
    //         cin >> zapros;
    //         switch (zapros)
    //         {
    //         case 1:
    //             date_sale.setDate();
    //             flats->getFlatsForData(date_sale);
    //             break;
    //         case 2:
    //             cout << "Введите месяц: ";
    //             cin >> month;
    //             cout << "Введите год: ";
    //             cin >> year;
    //             cout << "Выберите куда выходят окна: \nВо двор - 0\nНа улицу - 1\n";
    //             cin >> num;
    //             side = SIDE(num);
    //             flats->getFlatsForMonthAndSide(month, year, side);
    //             break;
    //         case 3:
    //             cout << "Введите год: ";
    //             cin >> year;
    //             flats->getFlatsForFirstHalfYear(year);
    //             break;
    //         case 4:
    //             cout << "Введите месяц: ";
    //             cin >> month;
    //             cout << "Введите год: ";
    //             cin >> year;
    //             cout << "Введите знак(>, <, =): ";
    //             cin >> znak;
    //             cout << "Введите стоимость: ";
    //             cin >> price;
    //             cout << flats->getFlatsForMonthAndPrice(month, year, price, znak);
    //             break;
    //         case 5:
    //             flats->getFlatsWithSale();
    //             break;
    //         case 6:
    //             cout << "Введите номер этажа: ";
    //             cin >> floor;
    //             flats->getFlatsWithSaleOnFloor(floor);
    //             break;
    //         case 7:
    //             cout << "Введите месяц: ";
    //             cin >> month;
    //             cout << "Введите год: ";
    //             cin >> year;
    //             flats->getPersentSaleFromFlatForMonth(month, year);
    //             break;
    //         default:
    //             break;
    //         }
    //         break;
    //     case 6:
    //         flats->saveToFile();
    //         break;
    //     case 7:
    //         flats->loadFromFile();
    //         break;
    //     default:
    //         break;
    //     }
    // }while(sw);

    delete flats;

    return 0;
}