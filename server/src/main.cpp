#include <iostream>

#include "DBConnector.hpp"

int main() {
    std::cout << "Hello world" << std::endl;

    DBConnector::getInstance().connect("127.0.0.1", "root", "MVAQS1105", "symfony");
    return 0;
}

