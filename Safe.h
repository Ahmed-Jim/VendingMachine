#ifndef VENDINGMACHINESYSTEM_SAFE_H
#define VENDINGMACHINESYSTEM_SAFE_H

#include <vector>
#include "Money.h"

using  namespace std;

class Safe {
private:
    vector<TwentyPill> Twenties;
    vector<TenPill> Tens;
    vector<FivePill> Fives;
    vector<Pound> Pounds;
    vector<HalfPound> Halves;
    float Total;

    void addTwenty();
    void addTen();
    void addFive();
    void addPound();
    void addHalf();

    void removeTwenty();
    void removeTen();
    void removeFive();
    void removePound();
    void removeHalf();

    void add(float amount);
    string remove(float change);
public:
    Safe();

    string pay(float amount,float wanted);

};


#endif //VENDINGMACHINESYSTEM_SAFE_H
