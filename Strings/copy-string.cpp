#include <iostream>

using namespace std;
int main() {
    char str1[100], str2[100];

    cout << "Enter a string: ";
    cin.get(str1, 100);

    int i;

    for (i = 0; str1[i] != '\0'; i++) {
        str2[i] = str1[i];
    }

    str2[i] = '\0';

    cout << "Copied string is: " << str2 << endl;

    return 0;
}