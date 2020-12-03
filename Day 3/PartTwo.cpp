#include <iostream>
#include <fstream>

int main() {
    std::fstream file;
    file.open("input.txt");
    std::string line;
    int lineNumber = 0;

    // first number is slope, second number is treeCount
    int slopes[5][2] = {{1, 0}, {3, 0}, {5, 0}, {7, 0}, {1, 0}};

    while(getline(file, line)) {
        for(int i = 0; i < 4; ++i) {
            if(line[lineNumber * slopes[i][0] % line.length()] == '#')
                ++slopes[i][1];
        }

        if(lineNumber % 2 == 0 && line[(lineNumber / 2) * slopes[4][0] % line.length()] == '#')
            ++slopes[4][1];

        ++lineNumber;
    }

    for(int i = 0; i < 5; ++i)
        std::cout << "Slope: " << slopes[i][0] << ", Trees hit: "
            << slopes[i][1] << std::endl;

    file.close();

    return 0;
}