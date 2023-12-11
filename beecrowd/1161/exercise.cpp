#include <iostream>


long long factorial(int factor) {
    long long result = 1;

    for(int i = 1; i <= factor; i++) {
        result *= i;
    }

    return result;
}


int main() {
    int left, right;

    while(std::cin >> left >> right) {
        std::cout << factorial(left) + factorial(right) << std::endl;
    }

    return 0;
}