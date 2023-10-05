#include <iostream>
#include <functional>

using namespace std;

void shell_sort() {
    string data = "INSERTIONSORT";
    int n = data.length(), h = 1, count = 0;

    while (h < n/3) {
        h = (h * 3) + 1;
    }

    while (h >= 1) {
        for (int i = h; i < n; i++) {
            for (int j = i; j >= h && data[j] < data[j - h]; j -= h) {
                swap(data[j], data[j - h]);
            }
        }
        if (count == 1) break;
        h = h / 3;
        count++;
    }

    cout << data;
}

int main() {
    shell_sort();
}