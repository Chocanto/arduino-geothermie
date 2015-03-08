#include "digitalpin.h"

using namespace pins;

DigitalPin::DigitalPin(int pin, int iomode)
: Pin(pin), m_iomode(iomode)
{

}

/*
DigitalPin::DigitalPin(const DigitalPin &digitalpin)
{
    *this = &digitalpin;
}*/

DigitalPin& DigitalPin::operator=(const DigitalPin &digitalpin)
{
    Pin::operator=(digitalpin);
    m_iomode = digitalpin.m_iomode;
    return *this;
}

int DigitalPin::getIoMode() const
{
    return m_iomode;
}

void DigitalPin::setup()
{
    pinMode(getPin(), m_iomode);
}

void DigitalPin::write(int value)
{
    if(m_iomode == OUTPUT)
        digitalWrite(getPin(), value);
}

int DigitalPin::read()
{
    if(m_iomode == INPUT)
        return digitalRead(getPin());
    else
        return LOW;
}

