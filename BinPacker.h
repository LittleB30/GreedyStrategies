// Alex Smith
// Header file for a BinPacker class that performs 5 different bin packing strategies

#ifndef BINPACKER_H
#define BINPACKER_H

#include "Bin.h"
#include <vector>

class BinPacker {
private:
    list<Bin> bins;

public:
    /*------Constructors------*/
    BinPacker();
    BinPacker(const BinPacker& orig);

    /*-------Destructor-------*/
    virtual ~BinPacker();

    /*-------Operators-------*/
    BinPacker& operator=(const BinPacker& orig);
    
    /*--------Methods--------*/
    void nextFit(list<int>& arr, ofstream& outStream);
    void firstFitOn(list<int>& arr, ofstream& outStream);
    void bestFitOn(list<int>& arr, ofstream& outStream);
    void firstFitOff(list<int>& arr, bool isSorted, ofstream& outStream);
    void bestFitOff(list<int>& arr, bool isSorted, ofstream& outStream);
    const list<Bin>& getBins();

private:
    void printRawData(ofstream& outStream);
    void printResults(ofstream& outStream);
    void emptyBins();
    void copyBinPacker(const BinPacker& orig);
};

#endif
