#include <iostream>
using namespace std;

int main(){
    int r1 = 2, c1 = 2, r2 = 2, c2 = 2;
    int matrix1[r1][c1];
    int matrix2[r2][c2];
    int product[r1][c2];

    for (int i = 0; i < r1; ++i)
    {
        for (int j = 0; j < c1; ++j)
        {
            cin >> matrix1[i][j];
            product[i][j] = 0;
        }
    }


    for (int i = 0; i < r2; i++)
    {
        for(int j = 0; j < c2; j++)
        {
            cin >> matrix2[i][j];
        }
    }


    for (int i = 0; i < r1; ++i)
    {
        for(int j = 0; j < c2; ++j)
        {
            for(int k = 0; k < c1; ++k)
            {
                product[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    for (int i = 0; i < r1; ++i)
    {
        cout << "[";
        for(int j = 0; j < c2; ++j)
        {
            cout << product[i][j]<<" ";
            cout << ",";
        }
        cout << "\b]";
        cout << endl;
    }
    return 0;
}