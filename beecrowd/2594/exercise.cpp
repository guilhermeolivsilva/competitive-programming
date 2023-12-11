#include <iostream>
#include <regex>
#include <sstream>
#include <string>


int main() {
    std::string text, wordToSearch, currentWord, output;
    bool matched;
    int currentIndex;
    int textCount;

    std::cin >> textCount;

    for(int i = 0; i < textCount; i++) {
        output = "";
        matched = false;
        currentIndex = 0;

        std::cin.ignore();
        std::getline(std::cin, text);
        std::cin >> wordToSearch;

        std::istringstream strStream(text);
        while(strStream >> currentWord) {
            if(currentWord == wordToSearch) {
                output += std::to_string(currentIndex) + " ";
                matched = true;
            }
            currentIndex += currentWord.size() + 1;
        }

        if(!matched) {
            output = "-1";
        } else {
            output = std::regex_replace(output, std::regex(" +$"), "");
        }

        std::cout << output << std::endl;
    }

    return 0;
}
