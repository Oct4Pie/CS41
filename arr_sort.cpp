#include <iostream>
using namespace std;

void sort(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i; j < size; j++) {
            if (arr[j] < arr[i]) {
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}

int main() {
    int arr[] = {6, 3, 7, 2, 5, 9, 1};
    sort(arr, 7);
    for (int i = 0; i < 7; i++) {
        cout << arr[i] << ", ";
    };
    cout << endl;
}

// ./arr_sort
// 1, 2, 3, 5, 6, 7, 9, 