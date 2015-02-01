#include <iostream>
#include <string>
#include "Pin.hpp"

using namespace std;

//
Pin::Pin(int id, int type,float iomode):
	m_id(id),m_type(type),m_iomode(iomode) {}
//
int Pin::getType() const{
	return m_type;
}

string Pin::getTypeStr() const{
    if (m_type == 0)
        return "A";
    else if (m_type == 1)
        return "D";
    else
        return "";
}
//
float Pin::getIomode() const{
	return m_iomode;
}
//
int Pin::getId() const{
	return m_id;
}
//
string Pin::toString(){
	int res = this -> getId();
	return ""+res;
}
