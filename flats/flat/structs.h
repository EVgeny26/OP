#ifndef STRUCT_H
#define STRUCT_H

#include <iostream>
#include <string>

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

template <typename T>
class Vector {
public:
    class VectorIterator {
        friend class Vector;
    public:
        VectorIterator(const VectorIterator& _it);
        bool operator==(const VectorIterator& _it) const;
        bool operator!=(const VectorIterator& _it) const;
        VectorIterator& operator++();
        VectorIterator& operator--();
        VectorIterator& operator+(size_t index);
        T& operator*() const;
    private:
        T* m_item;
        VectorIterator(T* _p);
    };

private:
    T* m_array{};
    T* m_end;
    size_t m_size{};

public:
    typedef VectorIterator iterator;
    typedef VectorIterator const_iterator;

    Vector();
    Vector(unsigned _size);
    ~Vector();

    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;

    size_t size() const { return m_size; }

    T& operator[](size_t index);
    const T& operator[](size_t index) const;

    // Добавленные методы для соответствия функциональности vector
    void push_back(const T& value);
    void pop_back();
    void insert(iterator position, const T& value);
    void erase(iterator position);
    void resize(size_t size);
    void clear();
    bool empty() const;
};

#endif //STRUCT_H