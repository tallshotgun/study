#include <iostream>
#include <vector>
using namespace std;

int main() {
    int rows = 3, cols = 4;

    // vector of vectors, initialized to 0
    vector<vector<int>> matrix(rows, vector<int>(cols, 0));

    // Fill
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            matrix[i][j] = i * cols + j;

    // Print
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }

    return 0;
} // memory is freed automatically