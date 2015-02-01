#ifndef DB_CONNECTOR_HPP
#define DB_CONNECTOR_HPP

#include <string>

#include <cppconn/driver.h>
#include <cppconn/connection.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>
#include <cppconn/exception.h>

#include "DateTime.hpp"

using namespace std;
using namespace sql;

class DBConnector {

    
    public:

        bool isConnected;

        static DBConnector& getInstance();
        void connect(string host, string user, string password, string database);
        void disconnect();
        void sendValueTest(int idC, int data, DateTime dt);
        void sendValueTest(int idC, int data);
        void send(string req);
        Connection* getConnection();
        static string dateTimeToString(DateTime date);
        static void exception(SQLException& );
    
    private:
    
        Driver *driver;
        Connection *con;
        Statement *stmt;
        PreparedStatement *pstmt;
        ResultSet *rs;

        DBConnector();
        DBConnector(DBConnector const&);
        void operator=(DBConnector const&);

};

#endif
