#include <iostream>

 
int main() {
    int input, idx;
    int thresholds[] = {1, 3, 5, 10, 25, 50, 100};
    
    while(std::cin >> input) {
        idx = 0;
        while(input > thresholds[idx]) {
            idx++;
        }
        std::cout << "Top " << thresholds[idx] << std::endl;
    }

    return 0;
}