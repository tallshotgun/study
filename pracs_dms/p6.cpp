#include <iostream>
#include <vector>
using namespace std;

bool isCompleteGraph(const vector<vector<int>>& matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                if (matrix[i][j] != 0) return false;
            } else {
                if (matrix[i][j] != 1) return false;
            }
        }
    }
    return true;
}

int main() {
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;

    if (n <= 0) {
        cout << "A graph must have at least one vertex." << endl;
        return 0;
    }

    vector<vector<int>> matrix(n, vector<int>(n));

    cout << "Enter the adjacency matrix (" << n << "x" << n << "):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    if (isCompleteGraph(matrix, n)) {
        cout << "\nThe given graph is a COMPLETE graph." << endl;
    } else {
        cout << "\nThe given graph is NOT a complete graph." << endl;
    }

    return 0;
}

/*
[tsglmao@arch pracs_dms]$ ./p6
Enter the number of vertices: 3
Enter the adjacency matrix (3x3):
0 1 1
1 0 1
1 1 0

The given graph is a COMPLETE graph.
[tsglmao@arch pracs_dms]$ ./p6
Enter the number of vertices: 3
Enter the adjacency matrix (3x3):
0 1 0
1 0 1
0 1 0

The given graph is NOT a complete graph.
[tsglmao@arch pracs_dms]$ 
*/