#include <string>
#include <cstdio>

#include "include/DBConnector.hpp"
#include "include/DateTime.hpp"

using namespace std;

DBConnector::DBConnector() {
    try {
        driver = get_driver_instance();
    }
    catch(SQLException &e) {
        exception(e);
    }

    isConnected = false;
    
}

DBConnector& DBConnector::getInstance() {
    static DBConnector instance;

    return instance;
}

void DBConnector::connect(string host, string user, string password, string database) {
    try {
        con = driver->connect("tcp://"+host, user, password);
        con->setSchema(database);
        this->con = con;
        isConnected = true;
    }
    catch(SQLException &e) {
        exception(e);
    }

}

void DBConnector::disconnect() {
    try {
        con->close();   
        delete con;

        driver->threadEnd();
        
        isConnected = false;
    }
    catch(SQLException &e) {
        exception(e);
    }
}

void DBConnector::sendValueTest(int idC, int data, DateTime dt) {
    try {
        pstmt = con->prepareStatement("INSERT INTO Donnees(idC, date, valeur) VALUES(?, ?, ?)");
        pstmt->setInt(1, idC);
        pstmt->setDateTime(2, dateTimeToString(dt));
        pstmt->setInt(3, data);
        pstmt->execute();
        pstmt->close();
        delete pstmt;
    }
    catch(SQLException &e) {
        exception(e);
    }
}

void DBConnector::sendValueTest(int idC, int data) {
    sendValueTest(idC, data, DateTime::now());
}

void DBConnector::exception(SQLException &e) {
    cout << "ERROR: SQLException in " << __FILE__;
    cout << " (" << __func__ << ") on line " << __LINE__ << endl;
    cout << "ERROR: " << e.what();
    cout << " (MySQL error code: " << e.getErrorCode();
    cout << ", SQLState: " << e.getSQLState() << ")" << endl;
}

string DBConnector::dateTimeToString(DateTime date) {
    ostringstream stringStream;
    stringStream << date.year() << "-" << date.month() << "-" << date.day() << " " << date.hour() << ":" << date.minute() << ":" << date.second();
    return stringStream.str();
}

Connection* DBConnector::getConnection() {
    if (!isConnected)
        return NULL;
    else
        return con;
}
