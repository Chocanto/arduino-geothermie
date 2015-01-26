#ifndef DB_INSTANCE_HPP 
#define DB_INSTANCE_HPP

#include <string>
#include <cppconn/prepared_statement.h>

using namespace std;
using namespace sql;

class DBInstance {
    public:
        DBInstance(string tableName);

        PreparedStatement* getNewPreparedStatement(string req);

        string getTableName();
    private:
        string tableName;
};

#endif
