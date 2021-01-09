// Alex Smith
// Header file for a Bin class that holds integers up to a certian capacity

#ifndef BIN_H
#define BIN_H

#include <fstream>
#include <list>

using namespace std;

class Bin {
private:
    /*------Data------*/
    int binNum; // name
    int usedCapacity;
    list<int> items;

public:
    static const int BIN_CAPACITY;

    /*------Constructors------*/
    Bin();
    Bin(int num);
    Bin(const Bin& orig);

    /*-------Destructor-------*/
    virtual ~Bin();

    /*-------Operators-------*/
    Bin& operator=(const Bin& orig);
    
    /*--------Methods--------*/
    pair<int,bool> doesItemFit(int item);
    void addItem(int item);
    void printBin(ostream& outStream);
    void emptyBin();
    const int getBinNum();
    const int getUsedCapacity();

private:
    void copyBin(const Bin& orig);
};

#endif
