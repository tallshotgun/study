#include <iostream>
#include <vector>
using namespace std;

void solve(int n, int target, vector<int>& current_solution) {
    if (n == 0) {
        if (target == 0) {
            cout << "(";
            for (int i = 0; i < current_solution.size(); ++i) {
                cout << current_solution[i] << (i == current_solution.size() - 1 ? "" : ", ");
            }
            cout << ")" << endl;
        }
        return;
    }

    for (int val = 0; val <= target; ++val) {
        current_solution.push_back(val);      
        solve(n - 1, target - val, current_solution);
        current_solution.pop_back();         
    }
}

int main() {
    int n, C;

    cout << "Enter the number of variables (n): ";
    cin >> n;
    cout << "Enter the constant sum (C <= 10): ";
    cin >> C;

    if (n <= 0) {
        cout << "n must be a positive integer." << endl;
        return 1;
    }

    vector<int> solution_path;
    cout << "\nAll non-negative integer solutions for x1 + ... + x" << n << " = " << C << ":\n";
    
    solve(n, C, solution_path);

    return 0;
}

/*
[tsglmao@arch pracs_dms]$ ./p4
Enter the number of variables (n): 3
Enter the constant sum (C <= 10): 5

All non-negative integer solutions for x1 + ... + x3 = 5:
(0, 0, 5)
(0, 1, 4)
(0, 2, 3)
(0, 3, 2)
(0, 4, 1)
(0, 5, 0)
(1, 0, 4)
(1, 1, 3)
(1, 2, 2)
(1, 3, 1)
(1, 4, 0)
(2, 0, 3)
(2, 1, 2)
(2, 2, 1)
(2, 3, 0)
(3, 0, 2)
(3, 1, 1)
(3, 2, 0)
(4, 0, 1)
(4, 1, 0)
(5, 0, 0)
[tsglmao@arch pracs_dms]$ 
*/