#include "gtest/gtest.h"
#include "DBConnector.hpp"
#include "Pins.hpp"

class TestPins : public ::testing::Test {
    protected:
        Pin* p1;
        Pin* p2;
        Pins* pins;

        virtual void SetUp() {
            p1 = new Pin(5,0,0);
            p2 = new Pin(7,1,1);

            pins = new Pins();
        }
        virtual void TearDown() {
            delete p1;
            delete p2;
            delete pins;
        }
};

TEST_F(TestPins, CreatePin) {

    EXPECT_EQ(5, p1->getId());
    EXPECT_EQ(7, p2->getId());
    EXPECT_EQ(0, p1->getType());
    EXPECT_EQ(1, p2->getType());
    EXPECT_EQ(0, p1->getIomode());
    EXPECT_EQ(1, p2->getIomode());
    EXPECT_EQ("A", p1->getTypeStr());
    EXPECT_EQ("D", p2->getTypeStr());

    p1->setId(6);

    EXPECT_EQ(6, p1->getId());
}

TEST_F(TestPins, PinsCollection) {

    EXPECT_FALSE(pins->contains(5));
   
    pins->createPin(*p1, false);
    ASSERT_TRUE(pins->contains(5));

    p2->setId(5);
    EXPECT_ANY_THROW(pins->createPin(*p2, false));

    pins->deletePin(5);
    EXPECT_FALSE(pins->contains(5));
}

TEST_F(TestPins, Persist) {
    int id = pins->createPin(*p1, true);
    ASSERT_NE(id, -1);

    Pins pins2 = Pins();
    pins2.recoverPersisted();
    ASSERT_TRUE(pins2.contains(id));
}
