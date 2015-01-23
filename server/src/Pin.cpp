#include <iostream>
#include "Pin.h"

using namespace std;
int Pin::s_lastId = 0;

//
Pin::Pin(int type,float iomode):
	m_type(type),m_iomode(iomode)
	{
		++ s_lastId;
		m_id = s_lastId;
	}
//
int Pin::getType() const{
	return m_type;
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
int Pin::getLastId(){
	return s_lastId;
}
//
string Pin::toString(){
	int res = this -> getId();
	return ""+res;
}
