#include <iostream>
using namespace std;

int global = 0;

int main()
{
    int x = 10;
    ++global;
    {
        x = 0;
        cout << x << endl;
    }
    cout << x << endl;
    return 0;

}