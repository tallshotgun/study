#include <iostream>

using namespace std;

int calcLength(const char* ptr);
void showAddresses(const char* str);
void concatenateStrings(char* dest, const char* src);
int compareStrings(const char* str1, const char* str2);
void toUppercase(char* str);
void reverseString(char* str);
void insertString(char* mainStr, const char* subStr, int pos);

int main() {
    char str1[1000];
    char str2[1000];
    char choice;
    int pos;

    do {
        cout << "\n========== STRING MANIPULATION MENU ==========\n";
        cout << "a. Show address of each character in string\n";
        cout << "b. Concatenate two strings\n";
        cout << "c. Compare two strings\n";
        cout << "d. Calculate length of the string (use pointers)\n";
        cout << "e. Convert all lowercase characters to uppercase\n";
        cout << "f. Reverse the string\n";
        cout << "g. Insert a string in another string at a user specified position\n";
        cout << "h. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        cin.ignore(1000, '\n');

        switch (choice) {
            case 'a':
            case 'A':
                cout << "Enter string: ";
                cin.getline(str1, 1000);
                showAddresses(str1);
                break;
            case 'b':
            case 'B':
                cout << "Enter first string: ";
                cin.getline(str1, 1000);
                cout << "Enter second string to append: ";
                cin.getline(str2, 1000);
                concatenateStrings(str1, str2);
                cout << "Concatenated string: " << str1 << endl;
                break;
            case 'c':
            case 'C':
                cout << "Enter first string: ";
                cin.getline(str1, 1000);
                cout << "Enter second string: ";
                cin.getline(str2, 1000);
                {
                    int res = compareStrings(str1, str2);
                    if (res == 0) cout << "Strings are exactly equal." << endl;
                    else if (res > 0) cout << "First string is greater." << endl;
                    else cout << "First string is smaller." << endl;
                }
                break;
            case 'd':
            case 'D':
                cout << "Enter string: ";
                cin.getline(str1, 1000);
                cout << "Length of the string is: " << calcLength(str1) << endl;
                break;
            case 'e':
            case 'E':
                cout << "Enter string: ";
                cin.getline(str1, 1000);
                toUppercase(str1);
                cout << "Uppercase string: " << str1 << endl;
                break;
            case 'f':
            case 'F':
                cout << "Enter string: ";
                cin.getline(str1, 1000);
                reverseString(str1);
                cout << "Reversed string: " << str1 << endl;
                break;
            case 'g':
            case 'G':
                cout << "Enter main string: ";
                cin.getline(str1, 1000);
                cout << "Enter string to insert: ";
                cin.getline(str2, 1000);
                cout << "Enter index position to insert (0 to " << calcLength(str1) << "): ";
                cin >> pos;
                insertString(str1, str2, pos);
                cout << "Modified string: " << str1 << endl;
                break;
            case 'h':
            case 'H':
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 'h' && choice != 'H');

    return 0;
}

int calcLength(const char* ptr) {
    int length = 0;
    while (*ptr != '\0') {
        length++;
        ptr++;
    }
    return length;
}

void showAddresses(const char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        cout << "Character '" << str[i] << "' at address: " << (void*)&str[i] << endl;
    }
}

void concatenateStrings(char* dest, const char* src) {
    int destLen = calcLength(dest);
    int i = 0;
    while (src[i] != '\0') {
        dest[destLen + i] = src[i];
        i++;
    }
    dest[destLen + i] = '\0';
}

int compareStrings(const char* str1, const char* str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return str1[i] - str2[i];
        }
        i++;
    }
    return str1[i] - str2[i];
}

void toUppercase(char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - ('a' - 'A');
        }
    }
}

void reverseString(char* str) {
    int len = calcLength(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
}

void insertString(char* mainStr, const char* subStr, int pos) {
    int mainLen = calcLength(mainStr);
    int subLen = calcLength(subStr);
    if (pos < 0 || pos > mainLen) return;
    for (int i = mainLen; i >= pos; i--) {
        mainStr[i + subLen] = mainStr[i];
    }
    for (int i = 0; i < subLen; i++) {
        mainStr[pos + i] = subStr[i];
    }
}

/*
[tsglmao@arch pracs_cpp]$ ./p4

========== STRING MANIPULATION MENU ==========
a. Show address of each character in string
b. Concatenate two strings
c. Compare two strings
d. Calculate length of the string (use pointers)
e. Convert all lowercase characters to uppercase
f. Reverse the string
g. Insert a string in another string at a user specified position
h. Exit
Enter your choice: a
Enter string: hello
Character 'h' at address: 0x7ffdec4213a0
Character 'e' at address: 0x7ffdec4213a1
Character 'l' at address: 0x7ffdec4213a2
Character 'l' at address: 0x7ffdec4213a3
Character 'o' at address: 0x7ffdec4213a4

========== STRING MANIPULATION MENU ==========
a. Show address of each character in string
b. Concatenate two strings
c. Compare two strings
d. Calculate length of the string (use pointers)
e. Convert all lowercase characters to uppercase
f. Reverse the string
g. Insert a string in another string at a user specified position
h. Exit
Enter your choice: b
Enter first string: hello
Enter second string to append: world
Concatenated string: helloworld

========== STRING MANIPULATION MENU ==========
a. Show address of each character in string
b. Concatenate two strings
c. Compare two strings
d. Calculate length of the string (use pointers)
e. Convert all lowercase characters to uppercase
f. Reverse the string
g. Insert a string in another string at a user specified position
h. Exit
Enter your choice: c
Enter first string: bigger
Enter second string: smaller
First string is smaller.

========== STRING MANIPULATION MENU ==========
a. Show address of each character in string
b. Concatenate two strings
c. Compare two strings
d. Calculate length of the string (use pointers)
e. Convert all lowercase characters to uppercase
f. Reverse the string
g. Insert a string in another string at a user specified position
h. Exit
Enter your choice: d
Enter string: hello world
Length of the string is: 11

========== STRING MANIPULATION MENU ==========
a. Show address of each character in string
b. Concatenate two strings
c. Compare two strings
d. Calculate length of the string (use pointers)
e. Convert all lowercase characters to uppercase
f. Reverse the string
g. Insert a string in another string at a user specified position
h. Exit
Enter your choice: e
Enter string: hElLo wOrlD
Uppercase string: HELLO WORLD

========== STRING MANIPULATION MENU ==========
a. Show address of each character in string
b. Concatenate two strings
c. Compare two strings
d. Calculate length of the string (use pointers)
e. Convert all lowercase characters to uppercase
f. Reverse the string
g. Insert a string in another string at a user specified position
h. Exit
Enter your choice: f
Enter string: dlrow olleh
Reversed string: hello world

========== STRING MANIPULATION MENU ==========
a. Show address of each character in string
b. Concatenate two strings
c. Compare two strings
d. Calculate length of the string (use pointers)
e. Convert all lowercase characters to uppercase
f. Reverse the string
g. Insert a string in another string at a user specified position
h. Exit
Enter your choice: g
Enter main string: he world         
Enter string to insert: llo
Enter index position to insert (0 to 8): 2
Modified string: hello world

========== STRING MANIPULATION MENU ==========
a. Show address of each character in string
b. Concatenate two strings
c. Compare two strings
d. Calculate length of the string (use pointers)
e. Convert all lowercase characters to uppercase
f. Reverse the string
g. Insert a string in another string at a user specified position
h. Exit
Enter your choice: h
Exiting program...
[tsglmao@arch pracs_cpp]$
*/