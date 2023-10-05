#include <iostream>
#include <algorithm> 

using namespace std;

void selection_sort() {
    string data = "INSERTIONSORT";
    int n = data.length();

    for (int i = 0, j, least; i < n - 1; i++) {
        for (int j = i + 1, least = i; j < n; j++) {
            if (data[j] < data[least]) {
                least = j;
            }
        }
        swap(data[least], data[i]);
        if (i == 2) {
            break;
        }
    }
    cout << data;
}

int main() {
    selection_sort();
}