#include <iostream>
#include <ctime>

using namespace std;

void bubble_sort() {
    srand(static_cast<unsigned int>(std::time(nullptr)));

    int arr[10];

    for (int i = 0; i < 10; i++) {
        arr[i] = rand() % (20 - 1 + 1) + 1;
        cout << arr[i] << " ";
    }

    bool isSwap = false;
    int temp = 0;

    for (int i = 0; i < 10; i++) {
        isSwap = false;
        for (int j = 0; j < 10; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                isSwap = true;
            }
        }
        cout << i << " ";
        if (isSwap == false) {
            break;
        }
    }

    cout << endl;

    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    bubble_sort();
}