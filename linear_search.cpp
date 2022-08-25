#include <iostream>
#include <random>
#define ARRAY_SIZE 15
using namespace std;

int search(int key, int* arr) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

int main() {
    srand(time(nullptr));
    default_random_engine rand_gen;
    uniform_int_distribution<int> randint(0, 50);
    int arr[ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; i++) {
        int num = randint(rand_gen);
        num += rand() % 50;
        arr[i] = num;
    }

    for (int i = 0; i < ARRAY_SIZE; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;

    int key = arr[rand() % ARRAY_SIZE];
    int index = search(key, arr);
    cout << "key: " << key << " is at " << index << endl;

    return 0;
}
