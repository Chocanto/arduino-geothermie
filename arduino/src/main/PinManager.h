#ifndef H_PINS_PINMANAGER
#define H_PINS_PINMANAGER

#include <vector>
#include <string>
#include "Arduino.h"
#include "PinFactory.h"
#include "pin.h"


namespace pins
{

    class PinManager
    {

        public:
            PinManager();

            void addPin(int pin,int type);

            void removePin(int type);

            void clear();

            void doMesure();

        private:
            PinFactory* factory;

            std::vector<Pin*> pinList;

            void send(String message);
            
            

    };

}

#endif

