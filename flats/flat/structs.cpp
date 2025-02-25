#include "structs.h"

void DATA::print(){
    cout<<day<<'.'<<month<<'.'<<year;
}
string DATA::get_string(){
    string data{to_string(day)+'.'+to_string(month)+'.'+to_string(year)};
    return data;
}

bool DATA::operator==(const DATA& other) const {
    return (year == other.year && month == other.month && day == other.day);
}bool DATA::operator!=(const DATA& other) const {
    return !(*this == other);
}

void ADDRESS::print(){
    cout<<region<<", "<<city<<", ул. "<<street<<" №"<<num_street;
    if(num_flat)cout<<" кв. "<<num_flat;
}
string ADDRESS::get_string(){
    string address{region+", "+city+", ул. "+street+" №"+to_string(num_street)};
    if(num_flat)address+=" кв. "+to_string(num_flat);
    return address;
}

bool ADDRESS::operator==(const ADDRESS& other) const {
    return (region == other.region) && (city == other.city) &&  (street == other.street) 
    && (num_street == other.num_street) && (num_flat == other.num_flat);
}bool ADDRESS::operator!=(const ADDRESS& other) const {
    return !(*this == other);
}