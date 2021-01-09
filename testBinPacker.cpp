// Alex Smith
// Main file to test how the bin packing strategies compare to each other

#include "BinPacker.h"
#include <iostream>

void fillArray(list<int>& arr, int numElements, ofstream& rawData) {
    arr.clear();
    rawData << "Original: ";
    for (int i = 0; i < numElements; i++) {
        arr.push_back(rand() % 100 + 1);
        rawData << arr.back() << " ";
    }
    rawData << endl;
}

void findBestOccurances(vector<int> binUsage[5], int bestOccurances[5]) {
    int best;
    for (int trial = 0; trial < 10; ++trial) {
        best = 100000;
        for (int strat = 0; strat < 5; ++strat) {
            if (binUsage[strat][trial] < best) {
                best = binUsage[strat][trial];
            }
        }
        for (int strat = 0; strat < 5; ++strat) {
            if (binUsage[strat][trial] == best) {
                bestOccurances[strat]++;
            }
        }
    }
}

double getAverage(vector<int>& arr) {
    double sum = 0;
    for (int num : arr) {
        sum += num;
    }
    return sum / arr.size();
}

void printTo(vector<int> binUsage[5], int bestOccurances[5], ostream& rawData) {
    rawData << "========Results========" << endl;
    rawData << "Next Fit performed the best " << bestOccurances[0] << " time" << ((bestOccurances[0] == 1)?"":"s") << " and averaged " << getAverage(binUsage[0]) << " bins." << endl;
    rawData << "First Fit Online performed the best " << bestOccurances[1] << " time" << ((bestOccurances[1] == 1)?"":"s") << " and averaged " << getAverage(binUsage[1]) << " bins." << endl;
    rawData << "Best Fit Online performed the best " << bestOccurances[2] << " time" << ((bestOccurances[2] == 1)?"":"s") << " and averaged " << getAverage(binUsage[2]) << " bins." << endl;
    rawData << "First Fit Offline performed the best " << bestOccurances[3] << " time" << ((bestOccurances[3] == 1)?"":"s") << " and averaged " << getAverage(binUsage[3]) << " bins." << endl;
    rawData << "Best Fit Offline performed the best " << bestOccurances[4] << " time" << ((bestOccurances[4] == 1)?"":"s") << " and averaged " << getAverage(binUsage[4]) << " bins." << endl;
    rawData << endl;
}

void printResults(vector<int> binUsage[5], ofstream& rawData) {
    int bestOccurances[5] = {0};
    findBestOccurances(binUsage, bestOccurances);
    printTo(binUsage, bestOccurances, rawData);
    printTo(binUsage, bestOccurances, cout);
}

int main(int argc, char const *argv[]){
    BinPacker bp;
    list<int> arr;
    vector<int> binUsage[5];
    srand(time(0));

    ofstream rawData("rawdata.txt");
    ofstream results("results.txt");
    for (int repeat = 1; repeat <= 10; ++repeat) {
        rawData << "################Trial " << repeat << "################" << endl;
        fillArray(arr, 100, rawData);
        bp.nextFit(arr, rawData);
        binUsage[0].push_back(bp.getBins().size());
        bp.firstFitOn(arr, rawData);
        binUsage[1].push_back(bp.getBins().size());
        bp.bestFitOn(arr, rawData);
        binUsage[2].push_back(bp.getBins().size());
        arr.sort(greater<int>());
        bp.firstFitOff(arr, true, rawData);
        binUsage[3].push_back(bp.getBins().size());
        bp.bestFitOff(arr, true, rawData);
        binUsage[4].push_back(bp.getBins().size());
        rawData << endl;
    }
    printResults(binUsage, results);

    rawData.close();
    results.close();
    return 0;
}
