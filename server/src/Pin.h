#ifndef H_PIN
#define H_PIN
#include <string>

class Pin{
	
	private:
		int m_type;
		float m_iomode;
		int m_id;
	
	public:
		static int s_lastId;
		Pin(int,float);
		int getType() const;
		float getIomode() const;
		int getId() const;
		static int getLastId();
		std::string toString();
};
#endif
