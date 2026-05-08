#include <iostream>
using namespace std;

int recursionGCD(int a, int b)
{
    if (b == 0) return a;   // HCF of 0 and any number is the number
    return recursionGCD(b, a % b);
}

int loopsGCD(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main()
{
    int a,b;
    cout << "Enter first number: ";
    cin >> a;
    cout << "Enter second number: ";
    cin >> b;
    cout << "Using recursion: " << recursionGCD(a,b) << "\nUsing loops: " << loopsGCD(a,b) << endl;

    return 0;
}

/*
[tsglmao@arch pracs_cpp]$ ./p7
Enter first number: 2048
Enter second number: 12
Using recursion: 4
Using loops: 4
[tsglmao@arch pracs_cpp]$
*/