#include "DBInstance.hpp"

#include <string>
#include <cppconn/prepared_statement.h>
#include <cppconn/connection.h>
#include <cppconn/resultset.h>

#include "DBConnector.hpp"

DBInstance::DBInstance(string tableName) {
    this->tableName = tableName;
}

string DBInstance::getTableName() const {
    return tableName;
}

PreparedStatement* DBInstance::getNewPreparedStatement(string req) const {
    return DBConnector::getInstance().getConnection()->prepareStatement(req);
}

int DBInstance::getLastInsertId() {
    sql::ResultSet* res = this->getNewPreparedStatement("SELECT LAST_INSERT_ID();")->executeQuery();
    res->next();
    return res->getInt(1);
}
    
