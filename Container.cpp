#include "Container.h"

Container::Container(const Product &product) : product(product) {
    Container::items = 10;
}

int Container::pop(float price) {
    if (product.getPrice() <= price and items > 0){
        items--;
        return items;
    }else{
        if(product.getPrice() > price){
            throw "Error: Container price mismatch.";
        } else{
            throw "Error: Container no more Items to remove.";
        }
    }
}

int Container::size() const {
    return items;
}

Container::Container(std::string Name, float price) : product(Product(Name, price)){
    Container::items = 10;
}

std::string Container::getProductInfo() {
    std::string Info = product.getName()+" - ";
    Info += product.getPrice();
    Info += "L.E";
    return  Info;
}

float Container::getProductPrice() {
    return product.getPrice();
}

std::string Container::getProductName(){
    return product.getName();
}