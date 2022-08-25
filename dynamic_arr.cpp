#include <iostream>
using namespace std;

int main() {
    int size;
    int inp;
    cout << "Please enter the array size: ";
    cin >> size;
    int arr_p[size]; // also works
    // int* arr_p = new int[size];

    cout << "Please enter the values" << endl;
    for (int i = 0; i < size; i++) {
        cin >> inp;
        if (inp == -1) {
            size = i;
            break;
        }
        arr_p[i] = inp;
    }

    for (int i = 0; i < size; i++) {
        cout << arr_p[i] << " ";
    }
    cout << endl;
    return 0;
}
