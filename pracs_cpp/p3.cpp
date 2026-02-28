#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main(int argc, char* argv[]) 
{
    // Array to count occurences of all 26 possible alphabets (lowercase only)
    int countArr[26] = {0};

    for (int i = 0; i < argc; ++i)
    {
        string word = argv[i];

        for (char c : word)
        {
            // Making 'a' as index 0. And converting each alphabet to lowercase for index purposes.   
            // ASCII value of each alphabet in lowercase will be given and substracting value of a from it will give its index in the array
            int index = tolower(c) - 'a'; 
            countArr[index]++;
        }
    }

    cout << "Letter | Occurence\n";
    for (int i = 0; i < 26; ++i)
    {
        char letter = 97 + i;
        if (countArr[i] > 0)
        {
            cout << ((char) (i + 'a')) << "      | " <<countArr[i] << endl;
        }
    }    

    return 0;
}