#include <iostream>

using namespace std;

int main() {
    char str1[100], str2[50];
    int i, j;

    cout << "Enter string 1: ";
    cin >> str1;

    cout << "Enter string 2: ";
    cin >> str2;

    for (i = 0; str1[i] != '\0'; i++);

    for (j = 0; str2[j] != '\0'; i++, j++) {
        str1[i] = str2[j];
    }

    str1[i] = '\0';

    cout << "Concatinated string: " << str1 << endl;
}