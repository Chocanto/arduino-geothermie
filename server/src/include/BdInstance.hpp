#ifndef DB_INSTANCE_HPP 
#define DB_INSTANCE_HPP

#include <cppconn/prepared_statement.h>

class DBInstance {
    public:
        DBInstance(string tableName);

        PreparedStatement getNewPreparedStatement(string req);

        string getTableName();
    private:
        string tableName;
}

#endif
