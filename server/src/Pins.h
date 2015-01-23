#ifndef H_PINS
#define H_PINS
#include <vector>

class Pin;

class Pins{
	
	private:
		std::vector<Pin> m_vectorPin;
		bool updatePins(std::vector<Pin> vectorsPin);
		bool contains(int id);
	
	public:
		Pins(std::vector<Pin> vectorsPin);
		int createPin(Pin pin);
		int deletePin(int id);
		std::vector<Pin> getPins() const;
};
#endif
