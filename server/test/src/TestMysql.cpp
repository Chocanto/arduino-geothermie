#include "gtest/gtest.h"
#include "include/DBConnector.hpp"

class MysqlTest : public ::testing::Test {
    
    protected:
        virtual void SetUp() {
        }

        virtual void TearDown() {
        }
};
    
TEST_F(MysqlTest, Connection) {
    DBConnector::getInstance().connect("localhost", "interface", "puits", "geothermie");
    EXPECT_TRUE(DBConnector::getInstance().isConnected);
}
