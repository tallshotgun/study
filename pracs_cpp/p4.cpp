#include <iostream>

using namespace std;

void showAddress(char* str)
{
    cout << "Char\t\tAddress\n";
    while (*str != '\0')
    {
        cout << *str << "\t\t   " << (void*)str << endl;
        str++;
    }
}

void concatenateStrings(char* s1, char* s2) {
    while (*s1 != '\0') s1++;
    while (*s2 != '\0') {
        *s1 = *s2;
        s1++;
        s2++;
    }
    *s1 = '\0';
}

int main()
{
    char s1[200],s2[100];
    cin.getline(s1,200);
    cin.getline(s2,100);
    concatenateStrings(s1,s2);
    cout << s1 << endl << s2 << endl;

    return 0;
}
