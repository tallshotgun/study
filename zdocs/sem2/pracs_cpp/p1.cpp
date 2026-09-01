#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main(int argc, char* argv[])
{
    int n;
    double sum = 0.0;
    if (argc>=2)
    {
        n = stoi(argv[1]);
        cout << "Using value of n from command line: " << n << endl;
    }
    else
    {
        cout << "No command line argument found.\nEnter Value of n: ";
        cin >> n;
    }

    for (int i = 1; i <= n; ++i)
    {
        double term = pow(-1,i+1)/pow(i,i) ;
        sum += term;
    }
    cout << sum << endl;

    return 0;
}

/*
[tsglmao@arch pracs_cpp]$ ./p1
No command line argument found.
Enter Value of n: 5
0.783451
[tsglmao@arch pracs_cpp]$ ./p1 5
Using value of n from command line: 5
0.783451
[tsglmao@arch pracs_cpp]$ 
*/