#include "DBInstance.hpp"
#include <cppcon/prepared_statement.h>
#include <cppcon/connection.h>

DBInstance::DBInstance(string tableName) {
    this.tableName = tableName;
}

string DBInstance::getTableName() {
    return tableName;
}

PreparedStatement DBInstance::getNewPreparedStatement(string req) {
    return con->prepareStatement(req);
}
