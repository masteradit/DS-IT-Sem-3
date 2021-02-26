#include <iostream>

using namespace std;

int len(char s[]) {
    int length;

    for (length = 0; s[length] != '\0'; length++);

    return length;
}

int main() {
    char str[100], substr[50];
    int pos, len1, len2;

    cout << "Enter the string: ";
    cin.get(str, 100);

    cout << "Enter the substring: ";
    cin.get(substr, 50);
    
    cout << "Enter the position to insert the substring into the string: ";
    cin >> pos;

    len1 = len(str);
    len2 = len(substr);

    for (int i = 1; i <= (len1 - pos); i++) {
        str[len1 + len2 - i] = str[len1 - i];
    }

    str[len1 + len2] = '\0';

    for (int j = 0; j < len2; j++) {
        str[pos + j] = substr[j];
    }

    cout << "New string: " << str << endl;

    return 0;
}