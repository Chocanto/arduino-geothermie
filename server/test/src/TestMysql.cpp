#include "gtest/gtest.h"
#include "include/DBConnector.hpp"
#include "include/Configurator.hpp"

class MysqlTest : public ::testing::Test {
    
    protected:
        virtual void SetUp() {
        }

        virtual void TearDown() {
        }
};
    
TEST_F(MysqlTest, Connection) {
    ASSERT_TRUE(Configurator::getInstance().readConfig("config_test.json"));
    DBConnector::getInstance().connect( Configurator::getInstance().getSettings()->get("db.host", "localhost"),
                                        Configurator::getInstance().getSettings()->get("db.user", "root"),
                                        Configurator::getInstance().getSettings()->get("db.password", "toor"),
                                        Configurator::getInstance().getSettings()->get("db.database", "geothermie") );
    EXPECT_TRUE(DBConnector::getInstance().isConnected);
}
