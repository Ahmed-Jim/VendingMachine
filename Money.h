#ifndef VENDINGMACHINESYSTEM_MONEY_H
#define VENDINGMACHINESYSTEM_MONEY_H

#include <string>

class Money {
public:
    std::string Type = "L.E.";

    virtual float Value()=0;
};

class TwentyPill : public Money {
    float Value(){
        return (float) 20;
    }
};

class TenPill : public Money{
    float Value(){
        return (float) 10;
    }
};


class FivePill : public Money{
    float Value(){
        return (float) 5;
    }
};


class Pound : public Money{
    float Value(){
        return (float) 1;
    }
};


class HalfPound : public Money{
    float Value(){
        return (float) 0.5;
    }
};


#endif //VENDINGMACHINESYSTEM_MONEY_H
