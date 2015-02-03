#include "gtest/gtest.h"
#include "include/Configurator.hpp"
#include <boost/property_tree/ptree.hpp>

class TestConfigurator : public ::testing::Test {
    protected:

        virtual void SetUp() {
        }
        virtual void TearDown() {
        }
};

TEST_F(TestConfigurator, Read) {
    ASSERT_NO_THROW(Configurator::getInstance().readConfig("./config_test.json"));
    ASSERT_NE("__error__", Configurator::getInstance().getSettings()->get("db.host", "__error__"));
}
