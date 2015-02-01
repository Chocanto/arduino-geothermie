#include "gtest/gtest.h"
#include "DBConnector.hpp"
#include "Pins.hpp"

class TestPins : public ::testing::Test {

    protected:
        virtual void SetUp() {}
        virtual void TearDown() {}
};

TEST_F(TestPins, CreatePin) {
    Pin p = Pin(5, 0, 0);

    EXPECT_EQ(5, p.getId());
    EXPECT_EQ(0, p.getType());
    EXPECT_EQ(0, p.getIomode());
    EXPECT_EQ("A", p.getTypeStr());

    p.setId(6);

    EXPECT_EQ(6, p.getId());
}
