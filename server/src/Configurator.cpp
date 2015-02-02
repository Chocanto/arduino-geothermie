#include <string>
#include <sstream>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>

#include "include/Configurator.hpp"

using namespace std;
using namespace boost::property_tree;


Configurator::Configurator() {
    pt = new ptree();
}

Configurator& Configurator::getInstance() {
    static Configurator instance;

    return instance;
}

bool Configurator::readConfig(string file) {
    try {
        json_parser::read_json(file, *pt);
    }
    catch (std::exception const& e) {
        cerr << e.what() << endl;
        return false;
    }
    return true;
}

ptree* Configurator::getSettings() {
    return pt;
}
