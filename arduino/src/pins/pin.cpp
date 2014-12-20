#include "pin.h"

Pin::Pin(int pin)
: m_pin(pin)
{
}

Pin::Pin(const Pin &pin)
{
	*this = pin;
}

Pin& Pin::operator=(const Pin &pin)
{
    m_pin = pin.m_pin;
	return *this;
}

int Pin::getPin() const
{
    return m_pin;
}