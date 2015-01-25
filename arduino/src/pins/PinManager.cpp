#include "PinManager.h"

using namespace std;

PinManager::PinManager(){
    PinManager::factory = new PinFactor();
}

void PinManager::addPin(int pin,int type){
    pinList.push_back(factory->createPin(type,pin));
}


void PinManager::removePin(int type){

}


void PinManager::clear(){
    pinList.erase(pinList.begin(), pinList.back());
}


void PinManager::doMesure(){
    string mesures="";
    for(int i =0; i<pinList.size();i++){
        Pin& lePin = pinList.at(i);
        mesures += lePin.getPin() + "," + lePin.read() + ";";
    }
    send(mesures);

}
void PinManager::send(string message){
    Serial.begin(9600);
    Serial.println(message);
    Serial.end();
}
