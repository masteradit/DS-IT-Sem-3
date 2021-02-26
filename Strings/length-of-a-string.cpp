#include <iostream>

using namespace std;

int main() {
    char str[100];
    int i = 0;

    cout << "Enter a string: ";
    cin >> str;

    for (i = 0; str[i] != '\0'; i++);

    cout << "Length of the string = " << i << endl;

    return 0;
}