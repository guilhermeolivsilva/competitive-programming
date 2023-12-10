#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>


int reverseNumber(int numberToInvert) {
    int reversedNumber = 0;
    while (numberToInvert > 0) {
        reversedNumber = reversedNumber * 10 + numberToInvert % 10;
        numberToInvert /= 10;
    }
    return reversedNumber;
}

int main() {
    int testCases, input, evaluatedNumber, expectedOutput;
    int treeDepth, _reverse;
    std::deque<int> currentLevelNodes, nextLevelNodes;
    std::vector<bool> testedValues(100000, false);

    std::cin >> testCases;

    while(testCases > 0) {
        testCases--;
        treeDepth = 0;
        evaluatedNumber = -1;
        currentLevelNodes.clear();
        nextLevelNodes.clear();
        testedValues.assign(100000, false);

        std::cin >> input >> expectedOutput;

        currentLevelNodes.push_back(input);

        while(evaluatedNumber != expectedOutput) {
            evaluatedNumber = currentLevelNodes.front();
            currentLevelNodes.pop_front();

            if(evaluatedNumber == expectedOutput) break;

            testedValues[evaluatedNumber] = 1;

            _reverse = reverseNumber(evaluatedNumber);

            if(!testedValues[_reverse]) {
                nextLevelNodes.push_back(_reverse);
                testedValues[_reverse] = true;
            }

            nextLevelNodes.push_back(evaluatedNumber + 1);

            if(currentLevelNodes.empty()) {
                currentLevelNodes.swap(nextLevelNodes);
                treeDepth++;
            }
        }

        std::cout << treeDepth << std::endl;
    }

    return 0;
}
