#ifndef VENDINGMACHINESYSTEM_PRODUCT_H
#define VENDINGMACHINESYSTEM_PRODUCT_H


#include <string>

class Product {
private:
    float price;
    std::string Name;
public:
    Product(std::string Name, float price);

    float getPrice() const;

    void setPrice(float price);

    const std::string &getName() const;

    void setName(const std::string &Name);

};


#endif //VENDINGMACHINESYSTEM_PRODUCT_H
