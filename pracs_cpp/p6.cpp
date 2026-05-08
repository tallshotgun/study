#include <iostream>
using namespace std;

int binSearchRecursion(const int arr[], int start, int end, int elem)
{   
    if (start <= end)    
    {
        int mid = start + (end - start) / 2;

        if (elem == arr[mid]) return mid;

        if (elem < arr[mid]) return binSearchRecursion(arr, start, mid - 1, elem);

        if (elem > arr[mid]) return binSearchRecursion(arr, mid + 1, end, elem);
    }    
    return -1;
}

int binSearchLoop(const int arr[],int low, int high, int elem)
{
    while (low <= high)
    {
        int mid = low + (high-low)/2;
        
        if (elem == arr[mid]) return mid;

        if (elem < arr[mid]) high = mid - 1;

        if (elem > arr[mid]) low = mid + 1;
    }
    return -1;
}

int main(int argc, char* argv[])
{
    int size, elemToFind;
    cout << "Enter number of elements you want in the array: ";
    cin >> size;
    int arr[size];
    cout << "Enter elements seperated by space:\n";

    for (int i = 0; i < size; ++i)
    {
        cin >> arr[i];
    }   
    
    cout << "Enter element to find: ";
    cin >> elemToFind;  

    int index1 = binSearchLoop(arr, 0, size - 1, elemToFind );
    int index2 = binSearchRecursion(arr, 0, size - 1, elemToFind);
    
    if (index1 != -1) cout << "Index without using recursion: " << index1 << endl;
    else cout << "Not found\n";

    if (index2 != -1) cout << "Index using recursion: " << index2 << endl;
    else cout << "Not found\n";
    
    return 0;    
}

/*
[tsglmao@arch pracs_cpp]$ ./p6
Enter number of elements you want in the array: 8
Enter elements seperated by space:
2 4 5 7 13 28 53 3
Enter element to find: 13
Index without using recursion: 4
Index using recursion: 4
[tsglmao@arch pracs_cpp]$
*/