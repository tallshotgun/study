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
/*
[tsglmao@arch pracs_dms]$ ./p3
Enter a set of digits (e.g., 123): 234

--- Permutations Without Repetition ---
234 243 324 342 432 423 
Total Permutations: 6

--- Permutations With Repetition ---
222 223 224 232 233 234 242 243 244 322 323 324 332 333 334 342 343 344 422 423 424 432 433 434 442 443 444 
Total Permutations: 27
[tsglmao@arch pracs_dms]$ 
*/