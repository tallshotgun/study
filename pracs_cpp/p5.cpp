#include <iostream>
using namespace std;


int main()
{
    int arr1size, arr2size;

    cout << "Enter number of elements you want in the first array: ";
    cin >> arr1size;
    int arr1[arr1size];
    cout << "Enter elements ONLY in increasing order and seperated by space:\n";
    
    for (int i = 0; i < arr1size; ++i)
    {
        cin >> arr1[i];
    }

    cout << "Enter number of elements you want in the second array: ";
    cin >> arr2size;
    int arr2[arr2size];
    cout << "Enter elements ONLY in increasing order and seperated by space:\n";

    for (int i = 0; i < arr2size; ++i)
    {
        cin >> arr2[i];
    }

    int newArrSize = arr1size + arr2size;
    int newArr[newArrSize];
    int count = 0,arr1ElemCount = 0,arr2ElemCount = 0;

    for (int i = 0; i < newArrSize; ++i) newArr[i] = 0; 

    while (arr1ElemCount < arr1size && arr2ElemCount < arr2size)
    {
        if (arr1[arr1ElemCount] < arr2[arr2ElemCount]) newArr[count++] = arr1[arr1ElemCount++];

        else newArr[count++] = arr2[arr2ElemCount++];
    }

    while (arr1ElemCount < arr1size) newArr[count++] = arr1[arr1ElemCount++]; 
    while (arr2ElemCount < arr2size) newArr[count++] = arr2[arr2ElemCount++]; 

    for (int i : newArr) cout << i << " "; 
    cout << endl;

    return 0;
}

/*
[tsglmao@arch pracs_cpp]$ ./p5
Enter number of elements you want in the first array: 5
Enter elements ONLY in increasing order and seperated by space:
2 4 5 7 8 
Enter number of elements you want in the second array: 4
Enter elements ONLY in increasing order and seperated by space:
1 3 9 11
1 2 3 4 5 7 8 9 11 
[tsglmao@arch pracs_cpp]$
*/