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

            /// methode qui crée un pin
            /// param type le type de pin
            /// param pin le numero du pin
            /// return le pointeur d'un pin
            Pin* createPin(int type,int pin);

            /// la constante du type analogique
            static const int typeAnalog;

            /// la constante du type numerique
            static const int typeDigital;

    };

}

#endif
