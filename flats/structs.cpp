#include "structs.h"

void DATA::print(){
    cout<<day<<'.'<<month<<'.'<<year;
}
string DATA::get_string(){
    string data{to_string(day)+'.'+to_string(month)+'.'+to_string(year)};
    return data;
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