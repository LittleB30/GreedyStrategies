// Alex Smith
// Implementation file for the Bin class

#include "Bin.h"

const int Bin::BIN_CAPACITY = 100;

/*------Constructors------*/
Bin::Bin() {
    binNum = 0;
    usedCapacity = 0;
}

Bin::Bin(int num) {
    binNum = num;
    usedCapacity = 0;
}

Bin::Bin(const Bin& orig) {
    copyBin(orig);
}

/*-------Destructor-------*/
Bin::~Bin() {}

/*-------Operators-------*/
Bin& Bin::operator=(const Bin& orig) {
    if (this != &orig) {
        copyBin(orig);
    }
    return *this;
}

/*--------Methods--------*/
pair<int,bool> Bin::doesItemFit(int item) {
    pair<int,bool> temp = make_pair(usedCapacity, false);
    int newCapacity = usedCapacity + item;
    if (newCapacity <= BIN_CAPACITY) {
        temp = make_pair(newCapacity, true);
    }
    return temp;
}

void Bin::addItem(int item) {
    pair<int,bool> temp = doesItemFit(item);
    if (temp.second) {
        items.push_back(item);
        usedCapacity = temp.first;
    }
}

void Bin::printBin(ostream& outStream) {
    outStream << "(" << usedCapacity << "/" << BIN_CAPACITY << "): ";
    for (int item : items) {
        outStream << item << " ";
    }
    outStream << endl;
}

void Bin::emptyBin() {
    items.clear();
}

const int Bin::getBinNum() {
    return binNum;
}

const int Bin::getUsedCapacity() {
    return usedCapacity;
}

void Bin::copyBin(const Bin& orig) {
    binNum = orig.binNum;
    usedCapacity = orig.usedCapacity;
    items = orig.items;
}