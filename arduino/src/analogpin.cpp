#include "analogpin.h"

using namespace pins;

AnalogPin::AnalogPin(int pin):
Pin(pin){

}

void AnalogPin::setup()
{

}

void AnalogPin::write(int value)
{
    analogWrite(getPin(), value);
}

int AnalogPin::read()
{
    return analogRead(getPin());
}

