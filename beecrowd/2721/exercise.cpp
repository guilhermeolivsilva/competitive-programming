#include <iostream>
#include <string>


int main() {
    long int input, totalSnowballs;
    std::string reindeers[] = {
        "Dasher",
        "Dancer",
        "Prancer",
        "Vixen",
        "Comet",
        "Cupid",
        "Donner",
        "Blitzen",
        "Rudolph"
    };

    totalSnowballs = 0;
    while(std::cin >> input) {
        totalSnowballs += input;
    }
    std::cout << reindeers[(totalSnowballs - 1) % 9] << std::endl;

    return 0;
}