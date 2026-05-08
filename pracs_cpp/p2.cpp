#include <iostream>
using namespace std;

int main()
{
    int size;
    cout << "Enter number of elements you want in the array: ";
    cin >> size;
    int arr[size];

    for (int i = 0; i < size; ++i)
    {
        cout << "Enter element " << i << " : ";
        cin >> arr[i];
    }

    cout << "Original Array:\n{";
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << ",";
    }
    cout << "\b}\n";
    
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

    cout << "\nFinal Array\n{";
    for (int i = newArrSize - 1; i >= 0; --i)
    {
        cout << newarr[i] << ",";
    }
    cout << "\b}\n";

    return 0;
}

/*
[tsglmao@arch pracs_cpp]$ ./p2
Enter number of elements you want in the array: 7
Enter element 0 : 2
Enter element 1 : 4
Enter element 2 : 3
Enter element 3 : 5
Enter element 4 : 2
Enter element 5 : 5
Enter element 6 : 6
Original Array:
{2,4,3,5,2,5,6}

Final Array
{2,4,3,5,6}
[tsglmao@arch pracs_cpp]$ 
*/