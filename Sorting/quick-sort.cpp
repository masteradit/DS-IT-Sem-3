#include <iostream>

using namespace std;

void quickSort(int a[], int low, int high) {
    if (low < high) {
        int i = low;
        int j = high + 1;
        int pivot = a[low];

        do {
            do {
                i++;
            } while (a[i] < pivot);

            do {
                j--;
            } while (a[j] > pivot);

            if (i < j) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        } while (i < j);

        int temp = a[low];
        a[low] = a[j];
        a[j] = temp;

        quickSort(a, low, j-1);

        quickSort(a, j+1, high);
    }
}

int main() {
    int n;

    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int a[n];

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int low = 0;
    int high = n - 1;

    cout << "Using quick sort" << endl;
    quickSort(a, low, high);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}
