#include "structs.h"
#include <algorithm>

ostream& operator<<(ostream& os, const DATE date){
    os<<date.day<<'.'<<date.month<<'.'<<date.year;
    return os;
}

void DATE::setDate(){
    cout << "Введите дату продажи:\n";
    cout << "Введите день: ";
    cin >> day;
    cout << "Введите месяц: ";
    cin >> month;
    cout << "Введите год: ";
    cin >> year;
}

string DATE::get_string(){
    string date{to_string(day)+'.'+to_string(month)+'.'+to_string(year)};
    return date;
}

bool DATE::operator==(const DATE& other) const {
    return (year == other.year && month == other.month && day == other.day);
}bool DATE::operator!=(const DATE& other) const {
    return !(*this == other);
}

bool DATE::operator<(const DATE& other) const {
    if (year < other.year) {
        return 1;
    } else if (year > other.year) {
        return 0;
    }
    if (month < other.month) {
        return 1;
    } else if (month > other.month) {
        return 0;
    }
    return (day < other.day);
}bool DATE::operator>=(const DATE& other) const {
    return !operator<(other);
}

bool DATE::operator<=(const DATE& other) const {
    if (year <= other.year) {
        return 1;
    } else if (year >= other.year) {
        return 0;
    }
    if (month <= other.month) {
        return 1;
    } else if (month >= other.month) {
        return 0;
    }
    return (day <= other.day);
}bool DATE::operator>(const DATE& other) const {
    return !operator<=(other);
}



ostream& operator<<(ostream& os, const ADDRESS address){
    os<<address.region<<", "<<address.city<<", ул. "<<address.street<<" №"<<address.num_street<<" кв. "<<address.num_flat;
    return os;
}
string ADDRESS::get_string(){
    string _region = region;
    string _city = city;
    string _street = street;
    replace(_region.begin(), _region.end(), ' ', '_');
    replace(_city.begin(), _city.end(), ' ', '_');
    replace(_street.begin(), _street.end(), ' ', '_');
    string address{_region+" "+_city+" "+_street+" "+to_string(num_street)+" "+to_string(num_flat)};
    return address;
}

bool ADDRESS::operator==(const ADDRESS& other) const {
    return (region == other.region) && (city == other.city) &&  (street == other.street) 
    && (num_street == other.num_street) && (num_flat == other.num_flat);
}bool ADDRESS::operator!=(const ADDRESS& other) const {
    return !(*this == other);
}

bool ADDRESS::operator>(const ADDRESS& other) const {
    if (region!=other.region)return region>other.region;
    if (city!=other.city)return city>other.city;
    if (street!=other.street)return street>other.street;
    if (num_street!=other.num_street)return num_street>other.num_street;
    if (num_flat!=other.num_flat)return num_flat>other.num_flat;
    return 0;    
}bool ADDRESS::operator<=(const ADDRESS& other) const {
    return !operator>(other);
}

void ADDRESS::setAddress(){
    cout << "Введите адрес:\n";
    cout << "Введите регион: ";
    cin >> region;
    cout << "Введите город: ";
    cin >> city;
    cout << "Введите улицу: ";
    cin >> street;
    cout << "Введите номер дома: ";
    cin >> num_street;
    cout << "Введите номер квартиры: ";
    cin >> num_flat;
}

bool ADDRESS::operator>=(const ADDRESS& other) const {
    if (region!=other.region)return region>=other.region;
    if (city!=other.city)return city>=other.city;
    if (street!=other.street)return street>=other.street;
    if (num_street!=other.num_street)return num_street>=other.num_street;
    if (num_flat!=other.num_flat)return num_flat>=other.num_flat;
    return 0;    
}bool ADDRESS::operator<(const ADDRESS& other) const {
    return !operator>=(other);
}


// myvector
#include "flat.h"

template <typename T>
Vector<T>::VectorIterator::VectorIterator(const VectorIterator& _it) : m_item(_it.m_item) {}

template <typename T>
bool Vector<T>::VectorIterator::operator==(const VectorIterator& _it) const {
    return m_item == _it.m_item;
}

template <typename T>
bool Vector<T>::VectorIterator::operator!=(const VectorIterator& _it) const {
    return m_item != _it.m_item;
}

template <typename T>
typename Vector<T>::VectorIterator& Vector<T>::VectorIterator::operator++() {
    m_item++;
    return *this;
}

template <typename T>
typename Vector<T>::VectorIterator& Vector<T>::VectorIterator::operator--(){
    m_item--;
    return *this;
}

template <typename T>
typename Vector<T>::VectorIterator& Vector<T>::VectorIterator::operator+(size_t index){
    m_item+=index;
    return *this;
}

template <typename T>
T& Vector<T>::VectorIterator::operator*() const {
    return *m_item;
}
template <typename T>
Vector<T>::VectorIterator::VectorIterator(T* _p) : m_item(_p) {}

template <typename T>
Vector<T>::Vector() : m_array(nullptr), m_end(nullptr), m_size(0) {}

template <typename T>
Vector<T>::Vector(unsigned _size) : m_size(_size) {
    m_array = new T[m_size];
    if (m_size) {
        T temp;
        for (int i = 0; i < m_size; ++i) {
            m_array[i] = temp;
        }
    }
    m_end = m_array + m_size;
}

template <typename T>
Vector<T>::~Vector<T>() {
    delete[] m_array;
}

template <typename T>
typename Vector<T>::iterator Vector<T>::begin() {
    return iterator(m_array);
}
template <typename T>
typename Vector<T>::iterator Vector<T>::end() {
    return iterator(m_end);
}
template <typename T>
typename Vector<T>::const_iterator Vector<T>::begin() const {
    return const_iterator(m_array);
}
template <typename T>
typename Vector<T>::const_iterator Vector<T>::end() const {
    return const_iterator(m_end);
}

template <typename T>
T& Vector<T>::operator[](size_t index) {
    if (index < m_size) {
        return m_array[index];
    }
    throw out_of_range("Index out of range"); // Или другой способ обработки ошибки
}

template <typename T>
const T& Vector<T>::operator[](size_t index) const {
    if (index < m_size) {
        return m_array[index];
    }
    throw out_of_range("Index out of range"); // Или другой способ обработки ошибки
}

template <typename T>
void Vector<T>::push_back(const T& value) {
    insert(end(), value);
}

template <typename T>
void Vector<T>::pop_back() {
    if (m_size > 0) {
        erase(--end());
    }
}

template <typename T>
void Vector<T>::insert(iterator position, const T& value) {
    size_t index = 0;
    for (iterator it = begin(); it != end(); ++it, ++index) {
        if (it == position) {
            break;
        }
    }

    T* new_array = new T[m_size + 1];
    for (size_t i = 0; i < index; ++i) {
        new_array[i] = m_array[i];
    }
    new_array[index] = value;
    for (size_t i = index; i < m_size; ++i) {
        new_array[i + 1] = m_array[i];
    }

    delete[] m_array;
    m_array = new_array;
    m_size++;
    m_end = m_array + m_size;
}

template <typename T>
void Vector<T>::erase(iterator position) {
    size_t index = 0;
    for (iterator it = begin(); it != end(); ++it, ++index) {
        if (it == position) {
            break;
        }
    }

    T* new_array = new T[m_size - 1];
    for (size_t i = 0; i < index; ++i) {
        new_array[i] = m_array[i];
    }
    for (size_t i = index + 1; i < m_size; ++i) {
        new_array[i - 1] = m_array[i];
    }

    delete[] m_array;
    m_array = new_array;
    m_size--;
    m_end = m_array + m_size;
}

template <typename T>
void Vector<T>::resize(size_t size){
    T* new_array = new T[size];
    if(m_size>=size){
        for (size_t i = 0; i < size; ++i) {
            new_array[i] = m_array[i];
        }
    }else{
        for (size_t i = 0; i < m_size; ++i) {
            new_array[i] = m_array[i];
        }
        for (size_t i = m_size; i < size; ++i) {
            new_array[i] = T();
        }
    }

    delete[] m_array;
    m_array = new_array;
    m_size=size;
    m_end = m_array + m_size;
}

template <typename T>
void Vector<T>::clear() {
    delete[] m_array;
    m_array = nullptr;
    m_end = nullptr;
    m_size = 0;
}

template <typename T>
bool Vector<T>::empty() const {
    return m_size == 0;
}

template class Vector<FLAT>;