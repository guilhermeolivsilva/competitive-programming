#include <algorithm>
#include <iostream>
#include <vector>

 
int main() {
    int left, right, numBoxes, lookUp;
    int i, j;
    std::vector<int> nutsAndBolts;    

    while(std::cin >> numBoxes) {
        for(i = 0; i < numBoxes; i++) {
            std::cin >> left >> right;

            for(j = left; j <= right; j++) {
                nutsAndBolts.push_back(j);
            }
        }

        std::cin >> lookUp;

        left = -1;
        right = -1;
        std::sort(nutsAndBolts.begin(), nutsAndBolts.end());

        for(j = 0; j < nutsAndBolts.size(); j++) {
            if(nutsAndBolts[j] == lookUp) {
                if(left == -1) { left = j; right = j; }
                else right = j;
            }
        }

        if(left != -1 && right != -1) {
            std::cout << lookUp << " found from " << left << " to " << right << std::endl;
        } else {
            std::cout << lookUp << " not found" << std::endl;
        }

        nutsAndBolts.clear();
    }
 
    return 0;
}