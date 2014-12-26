#ifndef H_PINS_DIGITALPIN
#define H_PINS_DIGITALPIN

#include "pin.h"
#include "Arduino.h"

namespace pins
{

/// Pins numériques de l'Arduino.
/// Les pins numériques sont configurés pour être utilisé exclusivement soit en
/// entrée, soit en sortie à la construction.
class DigitalPin : public Pin
{
    public:

    /// Constructeur.
    /// \param pin Le numero de port physique sur l'Arduino.
    /// \param iomode Le mode d'E/S (OUTPUT ou INPUT).
    DigitalPin(int pin, int iomode);

    /// Constructeur de copie.
    DigitalPin(const DigitalPin&);

    /// Opérateur d'assignation.
    DigitalPin& operator=(const DigitalPin&);

    /// \return Le mode d'E/S de la pin (OUTPUT ou INPUT)
    int getIoMode() const;

    void    setup();

    /// Methode d'écriture.
    /// Le mode d'E/S doit être OUTPUT.
    /// \param value La valeur à écrire (HIGH ou LOW).
    void    write(int value);

    /// Methode de lecture.
    /// Le mode d'E/S doit être INPUT.
    /// \return La valeur lue (HIGH ou LOW).
    int     read();


    private:

    int m_iomode;
};

}

#endif
