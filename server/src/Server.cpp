#include <iostream>
#include "Server.hpp"


using namespace std;

    Server::Server(){
        this->createConnectors();
    }

    Server::~Server(){
    }

    void Server::createConnectors(){
        DBConnector::getInstance().connect("","","","");
    }

}
