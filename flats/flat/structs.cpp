#include "structs.h"


ostream& operator<<(ostream& os, const DATA data){
    os<<data.day<<'.'<<data.month<<'.'<<data.year;
    return os;
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



ostream& operator<<(ostream& os, const ADDRESS address){
    os<<address.region<<", "<<address.city<<", ул. "<<address.street<<" №"<<address.num_street;
    if(address.num_flat)os<<" кв. "<<address.num_flat;
    return os;
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