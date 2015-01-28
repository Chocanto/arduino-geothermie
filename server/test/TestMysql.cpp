#include "gtest/gtest.h"
#include "DBConnector.hpp"

TEST(MysqlTest, Connection) {
    DBConnector::getInstance().connect("localhost", "interface", "puits", "geothermie");
    EXPECT_EQ(DBConnector::getInstance().isConnected, true);
}
