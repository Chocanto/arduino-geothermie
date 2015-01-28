#include "DBInstance.hpp"

#include <string>
#include <cppconn/prepared_statement.h>
#include <cppconn/connection.h>

#include "DBConnector.hpp"

DBInstance::DBInstance(string tableName) {
    this->tableName = tableName;
}

string DBInstance::getTableName() {
    return tableName;
}

PreparedStatement* DBInstance::getNewPreparedStatement(string req) {
    return DBConnector::getInstance().getConnection()->prepareStatement(req);
}
