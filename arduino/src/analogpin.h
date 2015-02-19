#ifndef H_PINS_ANALOGPIN
#define H_PINS_ANALOGPIN

#include "pin.h"
#include "Arduino.h"

namespace pins
{

/// Pins analogiques de l'Arduino.
class AnalogPin : public Pin
{
    public:
    
    AnalogPin(int pin);
    
    void    setup();
    void    write(int value);
    int     read();
};

}

#endif
