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

int GCD(int a, int b)
{
    int gcd;
    for (int i = 1; i < b; i++)
        {
            if (a % i == 0 && b % i == 0) gcd = i;
        }
    return gcd;
}

int main()
{
    int a,b;
    cin >> a >> b;
    cout << "Using recursion: " << recursionGCD(a,b) << "\nUsing loops: " << loopsGCD(a,b) << "\nExtra method: " << GCD(a,b) << endl;

    return 0;
}