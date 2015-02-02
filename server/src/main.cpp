#include <iostream>

#include "include/DBConnector.hpp"
#include "include/DemoValues.hpp"

int main() {
    DBConnector::getInstance().connect("localhost", "interface", "puits", "geothermie");
    DemoValues *dv = new DemoValues();
    dv->runDemo();
    return 0;
}
