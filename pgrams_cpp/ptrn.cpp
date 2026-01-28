#include <iostream>

using namespace std;

int main()
{
    int height;
    cout << "How many lines do you want: ";
    cin >> height;
    for (int i(1);i<=height;++i)
    {
        int temp = height;
        for (temp;temp>i;--temp)
        {
            cout << " ";
        }
        for (int b = 0; b < i; ++b)
        {
            cout << "*";
        }
        cout << endl;
    }
    
    return 0;
}