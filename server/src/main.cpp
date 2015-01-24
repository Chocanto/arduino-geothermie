#include <iostream>

#include "DBConnector.hpp"
#include "DemoValues.hpp"

int main() {
    DBConnector::getInstance().connect("localhost", "interface", "puits", "geothermie");
    DemoValues *dv = new DemoValues();
    dv->runDemo();
    return 0;
}
