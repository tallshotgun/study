#include <iostream>
#include <fstream>

int main() {
    std::ifstream inputFile("input.txt");

    std::ofstream outputFile("output.txt");

    char ch;

    while (inputFile >> ch) {
        outputFile << ch;
    }

    return 0;
}