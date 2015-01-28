#include "PinManager.h"
#include <serstream>
#include <sstream>

using namespace std;
using namespace pins;

PinManager::PinManager(){
    factory = new PinFactory();
}

void PinManager::addPin(int pin,int type){
    pinList.push_back(factory->createPin(type,pin));
}


void PinManager::removePin(int type){

}


void PinManager::clear(){
    pinList.clear();
}


void PinManager::doMesure(){
    String mesures="";
    for(int i =0; i<pinList.size();i++){
        Pin* lePin = pinList.at(i);
        
        mesures += String(lePin->getPin()) + "," + String(lePin->read()) + ";";
        
    }
    send(mesures);
}

void PinManager::send(String message){

    Serial.println(message);
}

