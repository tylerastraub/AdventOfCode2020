#include <iostream>
#include <fstream>

int main() {
    std::ifstream file;
    file.open("input.txt");

    std::string line;

    int correctPasswords = 0;

    while(getline(file, line)) {
        int hyphen = line.find('-');
        int colon = line.find(':');
        int firstSpace = line.find_first_of(' ');

        int lowerBound = std::stoi(line.substr(0, hyphen + 1));
        int upperBound = std::stoi(line.substr(hyphen + 1, firstSpace - hyphen - 1));
        std::string characterRequired = line.substr(colon - 1, 1);
        std::string password = line.substr(colon + 1, line.length() - colon - 1);

        int charCount = 0;
        for(char c : password) {
            if(characterRequired[0] == c)
                ++charCount;
        }

        if(charCount >= lowerBound && charCount <= upperBound)
            ++correctPasswords;
    }

    std::cout << "Correct passwords: " << correctPasswords << std::endl;

    file.close();

    return 0;
}