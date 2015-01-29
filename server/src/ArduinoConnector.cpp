#include "ArduinoConnector.hpp"
#include <string>
#include <iostream>

using namespace std;

ArduinoConnector* ArduinoConnector::m_instance = NULL;


ArduinoConnector::ArduinoConnector(){
   m_isConnected = false;
}


// Singleton, methode a utiliser pour instancier ArduinoConnector
ArduinoConnector* ArduinoConnector::instance(){
  if(m_instance==NULL){
    m_instance = new ArduinoConnector;
    //cout << "Crea instance"<< endl;
  }
  //cout << "Fin meth" << endl;
  return m_instance;
}

// TODO
void waiting(int time){

}

// TODO
bool ArduinoConnector::connect(){
  return true;
}

// TODO
void ArduinoConnector::sendCommand(std::string command, std::vector<std::string> data) const{

}

// TODO
void ArduinoConnector::send(std::vector<std::string> data) const{

}

// A decommenter quand l'implementation sera possible
/*
// TODO
std::vector<std::string> ArduinoConnector::getDataFromPin(int pin) const{
return ArduinoConnector::get(pin);
}

// TODO
std::vector<std::string> ArduinoConnector::get(int pin) const{
  
}
*/
