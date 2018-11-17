#include "Product.h"


Product::Product(std::string Name, float price) : price(price), Name(Name) {
    if(price <= 0)
        throw "Error: Product Price Must Be positive non-zero value.";
    else if (Name.size() <= 0)
        throw "Error Product Name must be of 1+ length.";
}


float Product::getPrice() const {
    return price;
}

void Product::setPrice(float price) {
    if (price > 0)
        Product::price = price;
    else
        throw "Error: Product Price Must Be positive non-zero value.";
}

const std::string &Product::getName() const {
    return Name;
}

void Product::setName(const std::string &Name) {
    if (Name.size() > 0)
        Product::Name = Name;
    else
        throw "Error Product Name must be of 1+ length.";
}
