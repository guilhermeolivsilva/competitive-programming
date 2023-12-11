#include <iostream>
#include <sstream>
#include <string>


int main() {
    std::string text, word;

    // Read an entire line
    std::cin.ignore();
    std::getline(std::cin, text);

    // Parse it word for word
    std::istringstream strStream(text);
    while(strStream >> word) {}

    return 0;
}