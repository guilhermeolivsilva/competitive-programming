#include <algorithm>
#include <iostream>
#include <string>
#include <vector>


int main() {
    int numCases, rgbCode;
    std::string mode;
    std::vector<int> colors;

    std::cin >> numCases;

    for(int i = 0; i < numCases; i++) {
        std::cin >> mode;
        for(int j = 0; j < 3; j++) {
            std::cin >> rgbCode;
            colors.push_back(rgbCode);
        }
        
        std::cout << "Caso #" << i + 1 << ": ";
        
        if(mode == "min") {
            std::cout << *std::min_element(colors.begin(), colors.end()) << std::endl;
        } else if(mode == "max") {
            std::cout << *std::max_element(colors.begin(), colors.end()) << std::endl;
        } else if(mode == "mean") {
            std::cout << (colors[0] + colors[1] + colors[2])/3 << std::endl;
        } else {
            std::cout << int(0.3 * colors[0] + 0.59 * colors[1] + 0.11 * colors[2]) << std::endl;
        }

        colors.clear();
    }


    return 0;
}