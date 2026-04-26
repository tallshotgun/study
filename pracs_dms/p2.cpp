#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <iomanip>

class RELATION {
private:
    int n;
    std::vector<std::string> labels;
    std::vector<std::vector<int>> matrix;
    std::map<std::string, int> nameToIndex;

public:
    // Constructor initializes the size and a zero-filled square matrix
    RELATION(int size) : n(size), matrix(size, std::vector<int>(size, 0)) {}

    void inputElements() {
        std::cout << "Enter the " << n << " elements of the set (separated by space):\n";
        for (int i = 0; i < n; i++) {
            std::string label;
            std::cin >> label;
            labels.push_back(label);
            nameToIndex[label] = i; // Map the string to its matrix index
        }
    }

    void addRelation(std::string u, std::string v) {
        if (nameToIndex.count(u) && nameToIndex.count(v)) {
            matrix[nameToIndex[u]][nameToIndex[v]] = 1;
        } else {
            std::cout << "Error: One or both elements not found in set. Ignored (" << u << ", " << v << ")\n";
        }
    }

    void displayMatrix() {
        std::cout << "\n--- Relation Matrix ---\n    ";
        for (const auto& l : labels) std::cout << std::setw(6) << l;
        std::cout << "\n";
        for (int i = 0; i < n; i++) {
            std::cout << std::setw(4) << labels[i];
            for (int j = 0; j < n; j++) {
                std::cout << std::setw(6) << matrix[i][j];
            }
            std::cout << "\n";
        }
    }

    void displayPairs() {
        std::cout << "\nRelation R = { ";
        bool first = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 1) {
                    if (!first) std::cout << ", ";
                    std::cout << "(" << labels[i] << "," << labels[j] << ")";
                    first = false;
                }
            }
        }
        std::cout << " }\n";
    }

    // 1. Reflexive: All diagonal elements must be 1
    bool isReflexive() {
        for (int i = 0; i < n; i++) {
            if (matrix[i][i] != 1) return false;
        }
        return true;
    }

    // 2. Symmetric: M[i][j] must equal M[j][i]
    bool isSymmetric() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] != matrix[j][i]) return false;
            }
        }
        return true;
    }

    // 3. Anti-symmetric: If M[i][j]=1 and M[j][i]=1, then i must equal j
    bool isAntiSymmetric() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && matrix[i][j] == 1 && matrix[j][i] == 1) return false;
            }
        }
        return true;
    }

    // 4. Transitive: If M[i][j]=1 and M[j][k]=1, then M[i][k] must be 1
    bool isTransitive() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 1) {
                    for (int k = 0; k < n; k++) {
                        if (matrix[j][k] == 1 && matrix[i][k] != 1) return false;
                    }
                }
            }
        }
        return true;
    }

    // Evaluate all properties and determine the overall relation type
    void checkRelationType() {
        bool r = isReflexive();
        bool s = isSymmetric();
        bool a = isAntiSymmetric();
        bool t = isTransitive();

        std::cout << "\n--- Properties ---\n";
        std::cout << "- Reflexive: " << (r ? "Yes" : "No") << "\n";
        std::cout << "- Symmetric: " << (s ? "Yes" : "No") << "\n";
        std::cout << "- Anti-symmetric: " << (a ? "Yes" : "No") << "\n";
        std::cout << "- Transitive: " << (t ? "Yes" : "No") << "\n";

        std::cout << "\n--- Conclusion ---\n";
        if (r && s && t) {
            std::cout << "The relation is an Equivalence Relation.\n";
        } else if (r && a && t) {
            std::cout << "The relation is a Partial Order Relation.\n";
        } else {
            std::cout << "None of the specific types.\n";
        }
        std::cout << std::endl;
    }
};

int main() {
    int n, numRelations;
    std::cout << "How many elements in the set? ";
    std::cin >> n;

    RELATION rel(n);
    rel.inputElements();

    std::cout << "\nHow many related pairs do you want to add? ";
    std::cin >> numRelations;

    for (int i = 0; i < numRelations; i++) {
        std::string u, v;
        std::cout << "Enter pair " << i + 1 << " (element1 element2): ";
        std::cin >> u >> v;
        rel.addRelation(u, v);
    }

    // Output the formatted data and final checks
    rel.displayMatrix();
    rel.displayPairs();
    rel.checkRelationType();

    return 0;
}