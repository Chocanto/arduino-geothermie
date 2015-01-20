#include <string>

#include "DBConnector.hpp"

#define NUMOFFSET 100
#define COLNAME 200

using namespace std;

DBConnector::DBConnector() {
    try {
        driver = get_driver_instance();
    }
    catch(SQLException &e) {
        exception(e);
    }
    
}

DBConnector& DBConnector::getInstance() {
    static DBConnector instance;

    return instance;
}

void DBConnector::connect(string host, string user, string password, string database) {
    try {
        con = driver->connect("tcp://"+host, user, password);
        con->setSchema(database);
    }
    catch(SQLException &e) {
        exception(e);
    }

}

void DBConnector::exception(SQLException &e) {
    cout << "ERROR: SQLException in " << __FILE__;
    cout << " (" << __func__ << ") on line " << __LINE__ << endl;
    cout << "ERROR: " << e.what();
    cout << " (MySQL error code: " << e.getErrorCode();
    cout << ", SQLState: " << e.getSQLState() << ")" << endl;
}

