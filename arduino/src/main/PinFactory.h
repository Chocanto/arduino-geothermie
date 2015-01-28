#ifndef H_PINS_PINFACTORY
#define H_PINS_PINFACTORY

#include "Arduino.h"
#include "analogpin.h"
#include "digitalpin.h"

namespace pins
{

    class PinFactory
    {

        public:

            Pin* createPin(int type,int pin);

            static const int typeAnalog;

            static const int typeDigital;

    };

}

#endif

