#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct Die {
    int sides;
    vector<double> probabilities;
};

void calculateSums(const vector<Die>& dice, map<int, double>& sums) {
    sums[0] = 1.0; // початкова сума з вірогідністю 1.0

    for (const Die& die : dice) {
        map<int, double> newSums;

        for (const auto& sumProb : sums) {
            int currentSum = sumProb.first;
            double currentProb = sumProb.second;

            for (int side = 1; side <= die.sides; ++side) {
                int newSum = currentSum + side;
                double newProb = currentProb * die.probabilities[side - 1];
                newSums[newSum] += newProb;
            }
        }

        sums = newSums;
    }
}

int main() {
    vector<Die> dice = {
            {2, {0.5, 0.5}},
            {4, {0.1, 0.2, 0.3, 0.4}},
            {6, {1.0 / 6, 1.0 / 6, 1.0 / 6, 1.0 / 6, 1.0 / 6, 1.0 / 6}},
            {8, {0.125, 0.125, 0.125, 0.125, 0.125, 0.125, 0.125, 0.125}},
            {10, {0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1}},
            {12, {1.0 / 12, 1.0 / 12, 1.0 / 12, 1.0 / 12, 1.0 / 12, 1.0 / 12,1.0 / 12, 1.0 / 12, 1.0 / 12, 1.0 / 12, 1.0 / 12, 1.0 / 12}},
            {20, {0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05,0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05}}
    };

    map<int, double> sums;
    calculateSums(dice, sums);

    cout << "All sum:" << endl;
    for (const auto& pair : sums) {
        cout << "Sum " << pair.first << ": Chance " << pair.second << endl;
    }

    return 0;
}