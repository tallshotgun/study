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
