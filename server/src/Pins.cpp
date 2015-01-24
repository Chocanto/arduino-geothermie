#include <iostream>
#include "Pin.h"
#include "Pins.h"

using namespace std;

//
Pins::Pins(vector<Pin> pins):
	m_vectorPin(pins){}
	
//
bool Pins::updatePins(vector<Pin> vectorPin){
	m_vectorPin = vectorPin;
	return true; 
} 
//
int Pins::createPin(Pin pin){
	if ( contains(pin.getId()) )
		return 0;
	m_vectorPin.push_back(pin);
	return 1;
}
//
int Pins::deletePin(int id){
	if ( !contains(id) ){
		return 0;
	}
	else{
		for ( int i = 0; i< m_vectorPin.size(); i++){
			if ( m_vectorPin[i].getId() == id ){
				//~ delete &m_vectorPin[i];
				m_vectorPin.erase(m_vectorPin.begin()+i);
				return 1;
			}
		}
		return 0;
	}
}
//
bool Pins::contains(int id){
	if ( id > Pin::getLastId() ){
		return false;
	}
	else{
		for ( int i = 0; i<  m_vectorPin.size(); i++){
			if ( m_vectorPin[i].getId() == id )
				return true;
		}
		return false;
	}
}
//
vector<Pin> Pins::getPins() const{ 
	return m_vectorPin;
}
