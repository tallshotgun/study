#include <iostream>
using namespace std;


int main()
{
    int arr1[] = {1,2,3,4,5,6,7,8,11,20,30}, arr2[] = {3,4,5,6,9,10,15,18};
    int arr1Size = sizeof(arr1)/sizeof(arr1[0]), arr2Size = sizeof(arr2)/sizeof(arr2[0]);
    int newArrSize = arr1Size + arr2Size;
    int newArr[newArrSize];
    int count = 0,arr1ElemCount = 0,arr2ElemCount = 0;

    for (int i = 0; i < newArrSize; ++i) newArr[i] = 0; 

    while (arr1ElemCount < arr1Size && arr2ElemCount < arr2Size)
    {
        if (arr1[arr1ElemCount] < arr2[arr2ElemCount]) newArr[count++] = arr1[arr1ElemCount++];

        else newArr[count++] = arr2[arr2ElemCount++];
    }

    while (arr1ElemCount < arr1Size) newArr[count++] = arr1[arr1ElemCount++]; 
    while (arr2ElemCount < arr2Size) newArr[count++] = arr2[arr2ElemCount++]; 

    for (int i : newArr) cout << i << " "; 
    cout << endl;

    return 0;
}