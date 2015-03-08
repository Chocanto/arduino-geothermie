#ifndef H_PINS_PINMANAGER
#define H_PINS_PINMANAGER

#include <vector>
#include <string>
#include "Arduino.h"
#include "PinFactory.h"
#include "pin.h"


namespace pins
{
/// classe  qui gere les Pin de l'arduino
    class PinManager
    {

        public:
            /// Constructeur
            PinManager();

            /// methode d'ajout de pin
            /// \param pin le numero du pin
            /// \param type le type de pin (\see PinFactory)
            void addPin(int pin,int type);

            void removePin(int type);

            /// methode qui supprime tout les pins
            void clear();

            /// methode qui récupere les mesures et les envoient en serial
            void doMesure();

        private:
            PinFactory* factory;

            std::vector<Pin*> pinList;

            void send(String message);



    };

}

#endif
