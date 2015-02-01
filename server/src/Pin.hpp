#ifndef H_PIN
#define H_PIN
#include <string>

class Pin{
	
	private:
		int m_type;
		float m_iomode;
		int m_id;
	
	public:
		Pin(int id=0, int type=0,float iomode=0);
		int getType() const;
        std::string getTypeStr() const;
		float getIomode() const;
		int getId() const;
        void setId(int id) { m_id = id; }
		std::string toString();
};
#endif
