#include "PinFactory.h"

const int PinFactory::typeDigital = 0;
const int PinFactory::typeAnalog = 1;

Pin& PinFactory::createPin(int type, int pin){
    Pin& res;
    if(type == PinFactory::typeDigital){
        res = Pin& (new DigitalPin(pin, 0));
    }else{
        res = Pin& (new AnalogPin(pin));
    }
    return res;
}
