#ifndef VENDINGMACHINESYSTEM_VENDINGMACHINE_H
#define VENDINGMACHINESYSTEM_VENDINGMACHINE_H

#include "Container.h"
#include "Safe.h"
#include <iostream>

using  namespace std;

class VendingMachine {
private:
    vector<Container> Containers;
    Safe safe;
    void printItems(bool quantity);
    bool isAvailable();
public:
    VendingMachine();

    void run(bool verbose);
};


#endif //VENDINGMACHINESYSTEM_VENDINGMACHINE_H
