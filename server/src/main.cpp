#include <iostream>

#include "include/DBConnector.hpp"
#include "include/DemoValues.hpp"
#include "include/Configurator.hpp"

int main() {

    Configurator::getInstance().readConfig("./config.json");

    DBConnector::getInstance().connect( Configurator::getInstance().getSettings()->get("db.host", "localhost"),
                                        Configurator::getInstance().getSettings()->get("db.user", "root"),
                                        Configurator::getInstance().getSettings()->get("db.password", "toor"),
                                        Configurator::getInstance().getSettings()->get("db.database", "geothermie") );
    DemoValues *dv = new DemoValues();
    dv->runDemo();
    return 0;
}
