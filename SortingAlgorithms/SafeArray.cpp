#include <iostream>
#include <algorithm> 
#include <ctime>

using namespace std;

class SafeArray {
    public:
        int** array;
        int length[5]; 

        SafeArray() {
            array = new int*[5];
        }

        void initialize() {
            srand(time(0));
            for (int i = 0; i < 5; i++) {
                length[i] = rand() % 10 + 1;
                array[i] = new int[length[i]];
                for (int j = 0; j < length[i]; j++) {
                    array[i][j] = rand() % 100 + 1;
                    cout << array[i][j] << " ";
                }
                cout << endl;
            }
        }

        void bubble_sort() {
            for (int k = 0; k < 5; k++) {
                for (int i = 0; i < length[k]; i++) {
                    for (int j = 0; j < length[k] - 1; j++) {
                        if (array[k][j] > array[k][j + 1]) {
                            int temp = array[k][j];
                            array[k][j] = array[k][j + 1];
                            array[k][j + 1] = temp;
                        }
                    }
                }
            }
        }

        void insertion_sort() {
            for (int k = 0; k < 5; k++) {
                for (int i = 1, j; i < length[k]; i++) {
                    int temp = array[k][i];
                    for (j = i; j > 0 && temp < array[k][j - 1]; j--) {
                        array[k][j] = array[k][j - 1];
                    }
                    array[k][j] = temp;
                }
            }
        }

        void selection_sort() {
            for (int k = 0; k < 5; k++) {
                for (int i = 0; i < length[k] - 1; i++) {
                    int least = i;
                    for (int j = i + 1; j < length[k]; j++) {
                        if (array[k][j] < array[k][least]) {
                            least = j;
                        }
                    }
                    if (least != i) {
                        swap(array[k][i], array[k][least]);
                    }
                }
            }
        }

        void display() {
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < length[i]; j++) {
                    cout << array[i][j] << " ";
                }
                cout << endl;
            }
        }
};

int main(){
    SafeArray sa;
    sa.initialize();
    cout << endl << endl;
    // sa.bubble_sort();
    // sa.insertion_sort();
    sa.selection_sort();
    sa.display();
}