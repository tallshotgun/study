#include <iostream>
#include <algorithm> // for std::sort

int main() {
    int arr[] = {1, 2, 3, 6, 5, 4, 2, 4, 6, 8, 8, 5, 4, 2, 5, 6, 8, 9, 4, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    // 1. Sort the array first: O(n log n)
    std::sort(arr, arr + n);

    // 2. In-place removal: O(n)
    if (n == 0) return 0; // Handle empty array

    int j = 0; // Index of the last unique element
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[j]) {
            j++;
            arr[j] = arr[i];
        }
    }

    // 3. The unique elements are now in arr[0 ... j]
    int newSize = j + 1;

    for (int i = 0; i < newSize; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}