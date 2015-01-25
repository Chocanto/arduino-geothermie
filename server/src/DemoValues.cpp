#include <time.h>
#include <unistd.h>

#include "DemoValues.hpp"
#include "DBConnector.hpp"

DemoValues::DemoValues() {
    srand(time(NULL));
}

int DemoValues::randomIntelValue(int value) {
    return value + (rand()%10+1)-5;
}

void DemoValues::runDemo() {
    if (DBConnector::getInstance().isConnected) {
        cout << "Running demo : " << endl;
        int values[4] = {0, 5, 10, 15};
        while(true) {
            for (int i=0; i < 4; i++) {
                values[i] = randomIntelValue(values[i]);
                DBConnector::getInstance().sendValueTest(i+1, values[i]);
                cout << values[i] << " added on " << i << endl;
            }
            sleep(2);
        }
    }
    else {
        cerr << "Cannot run demo without a configured database" << endl;
    }
}
