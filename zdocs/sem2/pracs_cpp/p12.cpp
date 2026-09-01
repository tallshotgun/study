#include <iostream>
#include <fstream>
using namespace std;

int main() 
{
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");
    
    char ch;

    while (inputFile >> ch) 
    {
        outputFile << ch;
    }

    return 0;
}