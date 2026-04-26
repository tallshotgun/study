#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <string>

class SET {
public:
    std::set<int> elements;
    std::string name;

    SET(std::string n = "Untitled") : name(n) {}

    void addElement(int val) { elements.insert(val); }

    void displayElements() const {
        std::cout << "{ ";
        for (auto it = elements.begin(); it != elements.end(); ++it) {
            std::cout << *it << (std::next(it) != elements.end() ? ", " : "");
        }
        std::cout << " }";
    }

    // a. Is Member
    bool isMember(int val) const {
        return elements.find(val) != elements.end();
    }

    // b. Power Set
    void powerSet() const {
        std::vector<int> v(elements.begin(), elements.end());
        int n = v.size();
        int powSize = pow(2, n);

        std::cout << "Power Set of " << name << ": { ";
        for (int i = 0; i < powSize; i++) {
            std::cout << "{";
            bool first = true;
            for (int j = 0; j < n; j++) {
                if ((i >> j) & 1) {
                    if (!first) std::cout << ",";
                    std::cout << v[j];
                    first = false;
                }
            }
            std::cout << "}" << (i == powSize - 1 ? "" : ", ");
        }
        std::cout << " }" << std::endl;
    }

    // c. Subset Check
    bool isSubsetOf(const SET& other) const {
        for (int x : elements) {
            if (!other.isMember(x)) return false;
        }
        return true;
    }

    // d, f. Binary Operations
    static SET unionSets(const SET& s1, const SET& s2) {
        SET res("Union");
        res.elements = s1.elements;
        res.elements.insert(s2.elements.begin(), s2.elements.end());
        return res;
    }

    static SET intersectSets(const SET& s1, const SET& s2) {
        SET res("Intersection");
        for (int x : s1.elements) if (s2.isMember(x)) res.addElement(x);
        return res;
    }

    static SET difference(const SET& s1, const SET& s2) {
        SET res("Difference");
        for (int x : s1.elements) if (!s2.isMember(x)) res.addElement(x);
        return res;
    }

    // g. Cartesian Product
    static void cartesianProduct(const SET& s1, const SET& s2) {
        std::cout << s1.name << " x " << s2.name << " = { ";
        bool first = true;
        for (int x : s1.elements) {
            for (int y : s2.elements) {
                if (!first) std::cout << ", ";
                std::cout << "(" << x << "," << y << ")";
                first = false;
            }
        }
        std::cout << " }" << std::endl;
    }
};

// Global State
std::vector<SET> setDatabase;
SET universalSet("Universal Set");

// Helper function to handle Set selection/creation seamlessly during operations
SET& selectOrCreate(std::string label) {
    std::cout << "\n--- Select or Create " << label << " ---\n";
    if (!setDatabase.empty()) {
        std::cout << "Existing Sets:\n";
        for (size_t i = 0; i < setDatabase.size(); ++i) {
            std::cout << "  [" << i << "] " << setDatabase[i].name << " = ";
            setDatabase[i].displayElements();
            std::cout << "\n";
        }
    } else {
        std::cout << "  [No existing sets available]\n";
    }
    
    std::cout << "Enter index of existing set, or enter -1 to CREATE a new set: ";
    int idx;
    std::cin >> idx;

    if (idx == -1) {
        std::string n;
        std::cout << "  > Enter new set name (e.g., SetA): "; 
        std::cin >> n;
        
        SET newSet(n);
        int size, val;
        std::cout << "  > Number of elements: "; 
        std::cin >> size;
        
        if (size > 0) {
            std::cout << "  > Enter " << size << " elements separated by space: ";
            for (int i = 0; i < size; i++) {
                std::cin >> val;
                newSet.addElement(val);
                // Automatically update the Universal Set with every new element entered
                universalSet.addElement(val); 
            }
        }
        setDatabase.push_back(newSet);
        return setDatabase.back();
    }
    
    return setDatabase.at(idx);
}

int main() {
    int choice;
    while (true) {
        std::cout << "\n========== SET OPERATIONS MENU ==========\n";
        std::cout << "1. Is Member (Check if element is in set)\n";
        std::cout << "2. Power Set\n";
        std::cout << "3. Subset Check (Is A a subset of B?)\n";
        std::cout << "4. Union & Intersection of two sets\n";
        std::cout << "5. Complement (Relative to dynamically built Universal Set)\n";
        std::cout << "6. Difference & Symmetric Difference\n";
        std::cout << "7. Cartesian Product\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter Choice: ";
        std::cin >> choice;

        if (choice == 0) break;

        try {
            switch (choice) {
                case 1: {
                    SET& s = selectOrCreate("Target Set");
                    int val;
                    std::cout << "\nEnter element to search for: "; 
                    std::cin >> val;
                    std::cout << "Result: " << (s.isMember(val) ? "True (It is a member)" : "False (Not a member)") << std::endl;
                    break;
                }
                case 2: {
                    SET& s = selectOrCreate("Target Set");
                    std::cout << "\n";
                    s.powerSet();
                    break;
                }
                case 3: {
                    SET& a = selectOrCreate("Set A (Potential Subset)");
                    SET& b = selectOrCreate("Set B (Potential Superset)");
                    std::cout << "\nResult: Is " << a.name << " a subset of " << b.name << "? -> " 
                              << (a.isSubsetOf(b) ? "True" : "False") << std::endl;
                    break;
                }
                case 4: {
                    SET& a = selectOrCreate("Set A");
                    SET& b = selectOrCreate("Set B");
                    std::cout << "\nUnion (" << a.name << " U " << b.name << "): "; 
                    SET::unionSets(a, b).displayElements();
                    std::cout << "\nIntersection (" << a.name << " n " << b.name << "): "; 
                    SET::intersectSets(a, b).displayElements();
                    std::cout << std::endl;
                    break;
                }
                case 5: {
                    SET& a = selectOrCreate("Set to Complement");
                    SET res = SET::difference(universalSet, a);
                    std::cout << "\nUniversal Set (Auto-generated from all inputs): ";
                    universalSet.displayElements();
                    std::cout << "\nComplement (" << a.name << "'): "; 
                    res.displayElements();
                    std::cout << std::endl;
                    break;
                }
                case 6: {
                    SET& a = selectOrCreate("Set A");
                    SET& b = selectOrCreate("Set B");
                    SET diff = SET::difference(a, b);
                    SET symm = SET::unionSets(SET::difference(a, b), SET::difference(b, a));
                    std::cout << "\nDifference (" << a.name << " - " << b.name << "): "; 
                    diff.displayElements();
                    std::cout << "\nSymmetric Difference (" << a.name << " Δ " << b.name << "): "; 
                    symm.displayElements();
                    std::cout << std::endl;
                    break;
                }
                case 7: {
                    SET& a = selectOrCreate("Set A");
                    SET& b = selectOrCreate("Set B");
                    std::cout << "\n";
                    SET::cartesianProduct(a, b);
                    break;
                }
                default:
                    std::cout << "Invalid selection. Please choose a valid operation.\n";
            }
        } catch (const std::out_of_range& e) {
            std::cout << "\nError: Invalid set index selected. Operation cancelled.\n";
        }
    }
    return 0;
}
/*
[tsglmao@arch pracs_dms]$ ./p1

========== SET OPERATIONS MENU ==========
1. Is Member (Check if element is in set)
2. Power Set
3. Subset Check (Is A a subset of B?)
4. Union & Intersection of two sets
5. Complement (Relative to dynamically built Universal Set)
6. Difference & Symmetric Difference
7. Cartesian Product
0. Exit
Enter Choice: 1

--- Select or Create Target Set ---
  [No existing sets available]
Enter index of existing set, or enter -1 to CREATE a new set: -1
  > Enter new set name (e.g., SetA): A
  > Number of elements: 3         
  > Enter 3 elements separated by space: 1 2 3

Enter element to search for: 2
Result: True (It is a member)

========== SET OPERATIONS MENU ==========
1. Is Member (Check if element is in set)
2. Power Set
3. Subset Check (Is A a subset of B?)
4. Union & Intersection of two sets
5. Complement (Relative to dynamically built Universal Set)
6. Difference & Symmetric Difference
7. Cartesian Product
0. Exit
Enter Choice: 1

--- Select or Create Target Set ---
Existing Sets:
  [0] A = { 1, 2, 3 }
Enter index of existing set, or enter -1 to CREATE a new set: -1
  > Enter new set name (e.g., SetA): B
  > Number of elements: 5
  > Enter 5 elements separated by space: 1 2 3 4 5

Enter element to search for: 6
Result: False (Not a member)

========== SET OPERATIONS MENU ==========
1. Is Member (Check if element is in set)
2. Power Set
3. Subset Check (Is A a subset of B?)
4. Union & Intersection of two sets
5. Complement (Relative to dynamically built Universal Set)
6. Difference & Symmetric Difference
7. Cartesian Product
0. Exit
Enter Choice: 2

--- Select or Create Target Set ---
Existing Sets:
  [0] A = { 1, 2, 3 }
  [1] B = { 1, 2, 3, 4, 5 }
Enter index of existing set, or enter -1 to CREATE a new set: 0

Power Set of A: { {}, {1}, {2}, {1,2}, {3}, {1,3}, {2,3}, {1,2,3} }

========== SET OPERATIONS MENU ==========
1. Is Member (Check if element is in set)
2. Power Set
3. Subset Check (Is A a subset of B?)
4. Union & Intersection of two sets
5. Complement (Relative to dynamically built Universal Set)
6. Difference & Symmetric Difference
7. Cartesian Product
0. Exit
Enter Choice: 3

--- Select or Create Set A (Potential Subset) ---
Existing Sets:
  [0] A = { 1, 2, 3 }
  [1] B = { 1, 2, 3, 4, 5 }
Enter index of existing set, or enter -1 to CREATE a new set: 0

--- Select or Create Set B (Potential Superset) ---
Existing Sets:
  [0] A = { 1, 2, 3 }
  [1] B = { 1, 2, 3, 4, 5 }
Enter index of existing set, or enter -1 to CREATE a new set: 1

Result: Is A a subset of B? -> True

========== SET OPERATIONS MENU ==========
1. Is Member (Check if element is in set)
2. Power Set
3. Subset Check (Is A a subset of B?)
4. Union & Intersection of two sets
5. Complement (Relative to dynamically built Universal Set)
6. Difference & Symmetric Difference
7. Cartesian Product
0. Exit
Enter Choice: 4

--- Select or Create Set A ---
Existing Sets:
  [0] A = { 1, 2, 3 }
  [1] B = { 1, 2, 3, 4, 5 }
Enter index of existing set, or enter -1 to CREATE a new set: 0

--- Select or Create Set B ---
Existing Sets:
  [0] A = { 1, 2, 3 }
  [1] B = { 1, 2, 3, 4, 5 }
Enter index of existing set, or enter -1 to CREATE a new set: 1

Union (A U B): { 1, 2, 3, 4, 5 }
Intersection (A n B): { 1, 2, 3 }

========== SET OPERATIONS MENU ==========
1. Is Member (Check if element is in set)
2. Power Set
3. Subset Check (Is A a subset of B?)
4. Union & Intersection of two sets
5. Complement (Relative to dynamically built Universal Set)
6. Difference & Symmetric Difference
7. Cartesian Product
0. Exit
Enter Choice: 5

--- Select or Create Set to Complement ---
Existing Sets:
  [0] A = { 1, 2, 3 }
  [1] B = { 1, 2, 3, 4, 5 }
Enter index of existing set, or enter -1 to CREATE a new set: 0

Universal Set (Auto-generated from all inputs): { 1, 2, 3, 4, 5 }
Complement (A'): { 4, 5 }

========== SET OPERATIONS MENU ==========
1. Is Member (Check if element is in set)
2. Power Set
3. Subset Check (Is A a subset of B?)
4. Union & Intersection of two sets
5. Complement (Relative to dynamically built Universal Set)
6. Difference & Symmetric Difference
7. Cartesian Product
0. Exit
Enter Choice: 6

--- Select or Create Set A ---
Existing Sets:
  [0] A = { 1, 2, 3 }
  [1] B = { 1, 2, 3, 4, 5 }
Enter index of existing set, or enter -1 to CREATE a new set: 0

--- Select or Create Set B ---
Existing Sets:
  [0] A = { 1, 2, 3 }
  [1] B = { 1, 2, 3, 4, 5 }
Enter index of existing set, or enter -1 to CREATE a new set: 1

Difference (A - B): {  }
Symmetric Difference (A Δ B): { 4, 5 }

========== SET OPERATIONS MENU ==========
1. Is Member (Check if element is in set)
2. Power Set
3. Subset Check (Is A a subset of B?)
4. Union & Intersection of two sets
5. Complement (Relative to dynamically built Universal Set)
6. Difference & Symmetric Difference
7. Cartesian Product
0. Exit
Enter Choice: 7

--- Select or Create Set A ---
Existing Sets:
  [0] A = { 1, 2, 3 }
  [1] B = { 1, 2, 3, 4, 5 }
Enter index of existing set, or enter -1 to CREATE a new set: 0

--- Select or Create Set B ---
Existing Sets:
  [0] A = { 1, 2, 3 }
  [1] B = { 1, 2, 3, 4, 5 }
Enter index of existing set, or enter -1 to CREATE a new set: 1

A x B = { (1,1), (1,2), (1,3), (1,4), (1,5), (2,1), (2,2), (2,3), (2,4), (2,5), (3,1), (3,2), (3,3), (3,4), (3,5) }

========== SET OPERATIONS MENU ==========
1. Is Member (Check if element is in set)
2. Power Set
3. Subset Check (Is A a subset of B?)
4. Union & Intersection of two sets
5. Complement (Relative to dynamically built Universal Set)
6. Difference & Symmetric Difference
7. Cartesian Product
0. Exit
Enter Choice: 0
[tsglmao@arch pracs_dms]$

*/