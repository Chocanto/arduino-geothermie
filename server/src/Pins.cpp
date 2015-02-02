#include <iostream>
#include <cppconn/resultset.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/exception.h>

#include "include/Pin.hpp"
#include "include/Pins.hpp"
#include "include/DBInstance.hpp"
#include "include/DBConnector.hpp"

using namespace std;
using namespace sql;

Pins::Pins(vector<Pin> pins):DBInstance("Capteur"), m_vectorPin(pins){}
	
bool Pins::updatePins(vector<Pin> vectorPin){
	m_vectorPin = vectorPin;
	return true; 
} 

int Pins::createPin(Pin pin, bool persist){
    int id = 1;
    if (persist) {
        try {
            PreparedStatement *pstmt = this->getNewPreparedStatement("INSERT INTO "+tableName+"(idD, typeC) VALUES(1, ?)");
            pstmt->setString(1, pin.getTypeStr());
            pstmt->execute();

            delete pstmt;
        }
        catch (SQLException &e) {
            DBConnector::getInstance().exception(e);
            return -1;
        }
        catch (exception &e) {
            cerr << e.what() << endl;
        }

        id = getLastInsertId();
        pin.setId(id);
    }
    else {
        if (contains(pin.getId())) {
            throw new runtime_error("Id already used");
            return -1;
        }
    }
	m_vectorPin.push_back(pin);
	return id;
}

int Pins::deletePin(int id){
	if ( !contains(id) ){
		return 0;
	}
	else{
		for ( int i = 0; i< m_vectorPin.size(); i++){
			if ( m_vectorPin[i].getId() == id ){
				//~ delete &m_vectorPin[i];
				m_vectorPin.erase(m_vectorPin.begin()+i);
				return 1;
			}
		}
		return 0;
	}
}

bool Pins::contains(int id){
    for ( int i = 0; i<  m_vectorPin.size(); i++){
        if ( m_vectorPin[i].getId() == id )
            return true;
    }
    return false;
}

vector<Pin> Pins::getPins() const{ 
	return m_vectorPin;
}

void Pins::recoverPersisted() {
    sql::ResultSet* res = this->getNewPreparedStatement("SELECT * FROM "+tableName)->executeQuery();
    int total = 0;
    string typeC;
    int typeInt;
    while (res->next()) {
        total++;
        typeC = res->getString("typeC");
        
        if (typeC == "A")
            typeInt = 0;
        else if (typeC == "D")
            typeInt = 1;
        else
            typeInt = -1;

        this->createPin(Pin(res->getInt("idC"), typeInt, 0), false);
    }
    delete res;
    cout << total << " pins found in database." << endl;
}
