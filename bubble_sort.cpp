#include <iostream>
using namespace std;

int main() {
    int data[] = {5, 2, 4, 1, 3};
    // 2, 5, 4, 1, 3
    // ...
    // 1, 2, 3, 4, 5
    int n = 5;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (data[j] > data[j + 1]) { // 5 > 2?
                swap(data[j], data[j + 1]);
            }
        }
    }

    cout << "Hasil Bubble Sort: ";
    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }

    return 0;
}
