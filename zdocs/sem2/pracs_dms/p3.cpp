#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void generateWithoutRepetition(string s, int left, int right, int &count) {
    if (left == right) {
        cout << s << " ";
        count++;
    } else {
        for (int i = left; i <= right; i++) {
            swap(s[left], s[i]);
            generateWithoutRepetition(s, left + 1, right, count);
            swap(s[left], s[i]);
        }
    }
}

void generateWithRepetition(string digits, string current, int length, int &count) {
    if (current.length() == length) {
        cout << current << " ";
        count++;
        return;
    }

    for (int i = 0; i < digits.length(); i++) {
        generateWithRepetition(digits, current + digits[i], length, count);
    }
}

int main() {
    string input;
    cout << "Enter a set of digits (e.g., 123): ";
    cin >> input;

    int countNoRep = 0;
    int countWithRep = 0;

    cout << "\n--- Permutations Without Repetition ---" << endl;
    generateWithoutRepetition(input, 0, input.length() - 1, countNoRep);
    cout << "\nTotal Permutations: " << countNoRep << endl;

    cout << "\n--- Permutations With Repetition ---" << endl;
    generateWithRepetition(input, "", input.length(), countWithRep);
    cout << "\nTotal Permutations: " << countWithRep << endl;

    return 0;
}