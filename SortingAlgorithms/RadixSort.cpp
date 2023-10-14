#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int get_max(int arr[], int n) {
    int maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

void count_sort(int arr[], int exp) {
    const int r = 10;
    const int n = 8; 
    int output[n];
    int count[r] = {0};

    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % r]++;
    }

    for (int i = 1; i < r; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % r] - 1] = arr[i];
        count[(arr[i] / exp) % r]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void radix_sort(int arr[], int n) {
    int maximum = get_max(arr, n);

    int exp = 1;

    while ((maximum / exp) > 0) {
        count_sort(arr, exp);
        exp = exp * 10;
    }
}

int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    const int n = sizeof(arr) / sizeof(int);

    cout << "Original Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    radix_sort(arr, n);

    cout << "Ascending Sorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << "\nDescending Sorted Array: ";
    for (int i = n - 1; i >= 0; i--) {
        cout << arr[i] << " ";
    }
}