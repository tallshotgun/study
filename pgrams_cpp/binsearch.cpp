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
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int elemToFind;
    cout << "Enter element to find: ";
    cin >> elemToFind;

    int size = sizeof(arr)/sizeof(arr[0]);

    int index1 = binSearchLoop(arr, 0, size - 1, elemToFind );
    int index2 = binSearchRecursion(arr, 0, size - 1, elemToFind);
    
    if (index1 != -1) cout << "Index without using recursion: " << index1 << endl;
    else cout << "Not found\n";

    if (index2 != -1) cout << "Index using recursion: " << index2 << endl;
    else cout << "Not found\n";
    
    return 0;    
}
