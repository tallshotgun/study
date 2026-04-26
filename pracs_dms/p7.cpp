#include <iostream>
#include <vector>

using namespace std;

void calculateDegrees(int vertices, const vector<vector<int>>& adj) {
    vector<int> in_degree(vertices, 0);
    vector<int> out_degree(vertices, 0);

    for (int i = 0; i < vertices; i++) {
        out_degree[i] = adj[i].size();

        for (int neighbor : adj[i]) {
            in_degree[neighbor]++;
        }
    }

    // Display the results
    cout << "\nVertex\tIn-Degree  Out-Degree" << endl;
    cout << "------------------------------------" << endl;
    for (int i = 0; i < vertices; i++) {
        cout << i << "\t" << in_degree[i] << "\t   " << out_degree[i] << endl;
    }
}

int main() {
    int v, e;
    cout << "Enter the number of vertices: ";
    cin >> v;
    cout << "Enter the number of edges: ";
    cin >> e;

    vector<vector<int>> adj(v);

    cout << "Enter edges (source to destination):" << endl;
    for (int i = 0; i < e; i++) {
        int u, dest;
        cin >> u >> dest;
        
        if (u < v && dest < v) {
            adj[u].push_back(dest);
        } else {
            cout << "Invalid vertex! Please use 0 to " << v - 1 << endl;
            i--; 
        }
    }

    calculateDegrees(v, adj);

    return 0;
}

/*
[tsglmao@arch pracs_dms]$ ./p7
Enter the number of vertices: 4
Enter the number of edges: 4
Enter edges (source to destination):
0 1
0 2
1 2
2 0

Vertex  In-Degree  Out-Degree
------------------------------------
0       1          2
1       1          1
2       2          1
3       0          0
[tsglmao@arch pracs_dms]$ 
*/