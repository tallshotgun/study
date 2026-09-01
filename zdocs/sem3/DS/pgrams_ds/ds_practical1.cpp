#include <iostream>
using namespace std;

int main() {
    int rows = 3, cols = 4;

    // allocating array of row-pointers
    int** matrix = new int*[rows];

    // allocating each row
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }

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

    //  free memory
    for (int i = 0; i < rows; i++)
        delete[] matrix[i];
    delete[] matrix;

    return 0;
}