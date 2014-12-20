#include "analogpin.h"

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