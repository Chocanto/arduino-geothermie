#ifndef H_PINS_PIN
#define H_PINS_PIN

#include "Arduino.h"

namespace pins
{

/// Classe de base abstraite pour la representation des pins de l'Arduino.
/// Déclare les methodes d'initialisation, d'écriture, et de lecture.
class Pin
{
	public:

    /// Constructeur.
    /// \param pin Le numero de port physique sur l'Arduino.
	Pin(int pin);
	
	/// Constructeur de copie.
	Pin(const Pin&);
	
	/// Opérateur d'assignation.
	Pin& operator=(const Pin&);
	
	/// \return Le numero de pin.
	int getPin() const;
	
	/// Methode d'initialisation.
	/// Appellée dans la methode principale setup de l'Arduino.
	virtual void setup() = 0;
	
	/// Methode d'écriture.
	/// \param value La valeur à écrire.
	virtual void write(int value) = 0;
	
	/// Methode de lecture.
	/// \return La valeur lue.
	virtual int read() = 0;
	
	
	private:
	
	int m_pin;
	
};

}

#endif
