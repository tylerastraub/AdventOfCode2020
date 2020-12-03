#include <iostream>
#include <fstream>

int main() {
    std::fstream file;
    file.open("input.txt");
    std::string line;
    int position = 0;
    int treeCount = 0;

    while(getline(file, line)) {
        if(line[position] == '#')
            ++treeCount;

        position += 3;

        if(position >= line.length())
            position -= (line.length());
    }

    std::cout << "Trees hit: " << treeCount << std::endl;

    file.close();

    return 0;
}