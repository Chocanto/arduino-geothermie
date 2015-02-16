#include "PinFactory.h"

using namespace pins;

const int PinFactory::typeDigital = 0;
const int PinFactory::typeAnalog = 1;

Pin* PinFactory::createPin(int type, int pin){
    Pin* res;
    if(type == PinFactory::typeDigital){
        res = new DigitalPin(pin, 0);
    }else{
        res = new AnalogPin(pin);
    }
    return res;
}

