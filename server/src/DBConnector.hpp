#ifndef DB_CONNECTOR_HPP
#define DB_CONNECTOR_HPP

#include <string>

#include <cppconn/driver.h>
#include <cppconn/connection.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include <cppconn/exception.h>

using namespace std;
using namespace sql;

class DBConnector {

    
    public:
        static DBConnector& getInstance();
        void connect(string, string, string, string);
    
    private:
    
        Driver *driver;
        Connection *con;
        Statement *stmt;
        ResultSet *rs;

        DBConnector();
        DBConnector(DBConnector const&);
        void operator=(DBConnector const&);

        static void exception(SQLException& );
};

#endif
