#include "Arduino.h"

// Initialisation.
void setup()
{

}

// Boucle principale.
void loop()
{

}

// Point d'entrée.
// Utilisée pour compatibilitée avec Make-Arduino.
// TODO : Supprimer / Trouver alternative ?
int main()
{
    init();
    setup();

    while(true)
        loop();
}
