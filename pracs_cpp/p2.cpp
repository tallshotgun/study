#include <iostream>
using namespace std;

int main()
{
    int arr[] = {1,2,3,6,5,4,2,4,6,8,8,5,4,2,5,6,8,9,4,3};
    int size = sizeof(arr)/sizeof(arr[0]);
    int newarr[size];
    int newArrSize = 0;
    
    for (int i = 0; i < size; ++i)
    {
        newarr[i] = 0;
    }    

    for (int i = size - 1; i >= 0; --i)
    {
        int index = size - i;
        int count = 0;
        for (int j = i; j >= 0; --j)
        {
            if (arr[i] == arr[j])
            {
                count++;
            }
        }
        if (count == 1)
        {
            newarr[newArrSize] = arr[i];
            newArrSize++;
        } 
    }

    for (int i = newArrSize - 1; i >= 0; --i)
    {
        cout << newarr[i] << " ";
    }
    cout << endl;

    return 0;
}