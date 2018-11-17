#include <sstream>
#include "Safe.h"

Safe::Safe() {
    Twenties = vector<TwentyPill>();
    Tens = vector<TenPill>();
    Fives = vector<FivePill>();
    Pounds = vector<Pound>();
    Halves = vector<HalfPound>();
    Total = 0;

    for (int i = 0; i < 20; ++i) {
        addTwenty();
        addTen();
        addFive();

        addPound();
        addHalf();
        addPound();
        addHalf();
    }
}

void Safe::addTwenty() {
    Total +=20;
    Twenties.push_back(TwentyPill());
}

void Safe::addTen() {
    Total +=10;
    Tens.push_back(TenPill());
}

void Safe::addFive() {
    Total +=5;
    Fives.push_back(FivePill());
}

void Safe::addPound() {
    Total+=1;
    Pounds.push_back(Pound());
}

void Safe::addHalf() {
    Total += 0.5;
    Halves.push_back(HalfPound());
}

void Safe::removeTwenty() {
    if(Twenties.size() > 0){
        Total -= 20;
        Twenties.pop_back();
    }else{
        throw "Error: Requested TwentyPill but safe has no twenties.";
    }
}

void Safe::removeTen()  {
    if(Tens.size() > 0){
        Total -= 10;
        Tens.pop_back();
    }else{
        throw "Error: Requested TenPill but safe has no Ten pills.";
    }
}

void Safe::removeFive() {
    if(Fives.size() > 0){
        Total -= 5;
        Fives.pop_back();
    }else{
        throw "Error: Requested FivePill but safe has no Five bills.";
    }
}


void Safe::removePound() {
    if(Pounds.size() > 0){
        Total -= 1;
        Pounds.pop_back();
    }else{
        throw "Error: Requested Pound but safe has no Pounds.";
    }
}


void Safe::removeHalf() {
    if(Halves.size() > 0){
        Total -= 0.5;
        Halves.pop_back();
    }else{
        throw "Error: Requested HalfPound but safe has no HalfPounds.";
    }
}

void Safe::add(float amount) {
    while(amount >= 0.5){
        if (amount >= 20){
            amount -= 20 ;
            addTwenty();
        }else if (amount >= 10){
            amount -= 10;
            addTen();
        }else if (amount >= 5){
            amount -=5;
            addFive();
        }else if (amount >=1 ){
            amount -=1;
            addPound();
        }else if(amount >= 0.5){
            amount -= 5;
            addHalf();
        } else{
            throw "Error:";
        }
    }
}

string Safe::remove(float change) {
    int M20p=0 , M10p=0 , M5p=0, M1p=0, M50c =0; // M20p => twenty pound Bill
    while (change >=0.5){
        if(change >= 20){
            change -=20;
            removeTwenty();
            M20p++;
        }else if(change >= 10){
            change -=10;
            removeTen();
            M10p++;
        }else if (change >=5 ){
            change -=5;
            removeFive();
            M5p ++;
        }else if (change >= 1){
            change -=1;
            removePound();
            M1p++;
        }else if(change >= 0.5){
            change -=0.5;
            removeHalf();
            M50c++;
        }
    }
    ostringstream ss;
    ss<<"Change: ";
    ss<<M20p;
    ss<<" Twenties, ";
    ss<< M10p;
    ss<<" Tens, ";
    ss<<M5p;
    ss<<" Fives, ";
    ss<<M1p;
    ss<<" Pounds, ";
    ss<<M50c;
    ss<<" Halves.";
    return  ss.str();
}

string Safe::pay(float amount, float wanted) {
    if(wanted  > amount){
        throw "Error: Wanted amount > payed Amount Safe can't complete the transaction.";
    }else if (wanted == amount){
        add(amount);
        return "Change: No Change!!";
    }else{
        add(amount);
        float change = amount - wanted;

        return remove(change);

    }
}