// Alex Smith
// Implementation file for the BinPacker class

#include "BinPacker.h"

using namespace std;

/*------Constructors------*/
BinPacker::BinPacker() {}

BinPacker::BinPacker(const BinPacker& orig) {
    copyBinPacker(orig);
}

/*-------Destructor-------*/
BinPacker::~BinPacker() {}

/*-------Operators-------*/
BinPacker& BinPacker::operator=(const BinPacker& orig) {
    if (this != &orig) {
        copyBinPacker(orig);
    }
    return *this;
}

/*--------Methods--------*/
void BinPacker::nextFit(list<int>& arr, ofstream& outStream) {
    emptyBins();
    outStream << "========Next Fit========" << endl;
    outStream << "Assignments: ";
    for (int num : arr) {
        if (bins.back().doesItemFit(num).second) {
            bins.back().addItem(num);
        }
        else {
            bins.push_back(Bin(bins.back().getBinNum() + 1));
            bins.back().addItem(num);
        }
        outStream << num << "(" << bins.back().getBinNum() << ") ";
    }
    outStream << endl;
    printRawData(outStream);
}

void firstFit(list<Bin>& bins, list<int>& arr, ofstream& outStream) {
    bool added;
    outStream << "Assignments: ";
    for (int num : arr) {
        outStream << num << "(";
        added = false;
        for (Bin& bin : bins) {
            if (bin.doesItemFit(num).second) {
                bin.addItem(num);
                added = true;
                outStream << bin.getBinNum();
                break;
            }
        }
        if (!added) {
            bins.push_back(Bin(bins.back().getBinNum() + 1));
            bins.back().addItem(num);
            outStream << bins.back().getBinNum();
        }
        outStream << ") ";
    }
    outStream << endl;
}

void BinPacker::firstFitOn(list<int>& arr, ofstream& outStream) {
    emptyBins();
    outStream << "========First Fit Online========" << endl;
    firstFit(bins, arr, outStream);
    printRawData(outStream);
}

void bestFit(list<Bin>& bins, list<int>& arr, ofstream& outStream) {
    Bin* bestBin = 0;
    int bestFit = 0;
    pair<int,bool> temp;
    outStream << "Assignments: ";
    for (int num : arr) {
        outStream << num << "(";
        for (Bin& bin : bins) {
            temp = bin.doesItemFit(num);
            if (temp.second && (!bestBin || temp.first > bestFit)) {
                bestBin = &bin;
                bestFit = temp.first;
            }
        }
        if (!bestBin) {
            bins.push_back(Bin(bins.back().getBinNum() + 1));
            bestBin = &bins.back();
        }
        outStream << bestBin->getBinNum() << ") ";
        bestBin->addItem(num);
        bestBin = 0;
        bestFit = 0;
    }
    outStream << endl;
}

void BinPacker::bestFitOn(list<int>& arr, ofstream& outStream) {
    emptyBins();
    outStream << "========Best Fit Online========" << endl;
    bestFit(bins, arr, outStream);
    printRawData(outStream);
}

void BinPacker::firstFitOff(list<int>& arr, bool isSorted, ofstream& outStream) {
    emptyBins();
    outStream << "========First Fit Offline========" << endl;
    if (!isSorted) arr.sort(greater<int>());
    firstFit(bins, arr, outStream);
    printRawData(outStream);
}

void BinPacker::bestFitOff(list<int>& arr, bool isSorted, ofstream& outStream){
    emptyBins();
    outStream << "========Best Fit Offline========" << endl;
    if (!isSorted) arr.sort(greater<int>());
    bestFit(bins, arr, outStream);
    printRawData(outStream);
}

const list<Bin>& BinPacker::getBins() {
    return bins;
}

void BinPacker::printRawData(ofstream& outStream) {
    for (Bin& bin : bins) {
        outStream << "Bin " << bin.getBinNum() << " ";
        bin.printBin(outStream);
    }
}

void BinPacker::emptyBins() {
    bins.clear();
    bins.push_back(Bin(1));// The first bin
}

void BinPacker::copyBinPacker(const BinPacker& orig) {
    bins = orig.bins;
}