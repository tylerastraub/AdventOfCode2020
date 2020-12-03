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

        int firstIndex = std::stoi(line.substr(0, hyphen + 1));
        int secondIndex = std::stoi(line.substr(hyphen + 1, firstSpace - hyphen - 1));
        std::string characterRequired = line.substr(colon - 1, 1);
        std::string password = line.substr(colon + 1, line.length() - colon - 1);

        bool validPassword = false;
        if((password[firstIndex] == characterRequired[0] && password[secondIndex] != characterRequired[0])
           ||
           (password[firstIndex] != characterRequired[0]&& password[secondIndex] == characterRequired[0]))
            ++correctPasswords;
    }

    std::cout << "Correct passwords: " << correctPasswords << std::endl;

    file.close();

    return 0;
}