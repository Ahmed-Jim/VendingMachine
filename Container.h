#ifndef VENDINGMACHINESYSTEM_CONTAINER_H
#define VENDINGMACHINESYSTEM_CONTAINER_H

#include "Product.h"

class Container {
private:
    int items;
    Product product;
public:
    Container(const Product &product);

    Container(std::string Name, float price);

    int pop(float price);

    int size() const;

    std::string getProductInfo();

    float getProductPrice();

    std::string getProductName();

};


#endif //VENDINGMACHINESYSTEM_CONTAINER_H
