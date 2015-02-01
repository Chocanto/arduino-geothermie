#ifndef H_PINS
#define H_PINS
#include <vector>

#include "Pin.hpp"
#include "DBInstance.hpp"

class Pins : public DBInstance {
	
	private:
		std::vector<Pin> m_vectorPin;
		bool updatePins(std::vector<Pin> vectorsPin);
		bool contains(int id);

	
	public:
		Pins(std::vector<Pin> vectorsPin=std::vector<Pin>());
        
        ///
        /// \brief Add a pin in pins collection
        /// \param pin The pin to add
        /// \param persist Persist the pin in DB
        ///
        /// \return int id The new ID of the pin if
        ///                persisted or 1 else
		int createPin(Pin pin, bool persist=true);
		int deletePin(int id);
		std::vector<Pin> getPins() const;
        
        ///
        /// \brief Recover every object persisted on BD
        ///        as part of the collection.
        virtual void recoverPersisted() override;
};
#endif
