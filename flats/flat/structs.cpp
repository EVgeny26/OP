#include "structs.h"

ostream& operator<<(ostream& os, const DATE date){
    os<<date.day<<'.'<<date.month<<'.'<<date.year;
    return os;
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
    string address{region+"-"+city+"-"+street+"-"+to_string(num_street)+"-"+to_string(num_flat)};
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