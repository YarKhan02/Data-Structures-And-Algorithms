#include <iostream>

using namespace std;

void insertion_sort() {
    string data = "INSERTIONSORT";
    int n = data.length();

    for (int i = 1, j; i < n; i++) {
        int temp = data[i];
        for (j = i; j > 0 && temp < data[j - 1]; j--) {
            data[j] = data[j - 1];
        }
        data[j] = temp;
        if (i == 3) {
            break;
        }
    }
    cout << data;
}

int main() {
    insertion_sort();
}