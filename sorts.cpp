#define WITHOUT_NUMPY
#include <cmath>
#include <iostream>
#include <random>
#include "matplt.h"
using namespace std;

namespace plt = matplotlibcpp;

int lsearch(int key, int* arr, int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

int bsearch(int key, int* arr, int s = 0, int e = 0) {
    while (e + s > 1) {
        int mid = (e - s) / 2;
        if (arr[mid] > key) {
            e = mid;
            continue;
        }
        if (arr[mid] < key) {
            s = -mid;
            continue;
        }
        return mid;
    }
    return -1;
}

int bsearch2(int key, int* arr, int lowerBound, int upperBound) {
    int middle;
    while (lowerBound <= upperBound) {
        middle = (lowerBound + upperBound) / 2;
        if (key < arr[middle]) {
            upperBound = middle - 1;
        } else if (key > arr[middle]) {
            lowerBound = middle + 1;
        } else
            return middle;
    }
    return -1;
}

void sort(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i; j < size; j++) {
            if (arr[i] > arr[j]) {
                int tmp = arr[j];
                arr[j] = arr[i];
                arr[i] = tmp;
            }
        }
    }
}

int main() {
    vector<double> t, elements;

    default_random_engine rand_gen;

    int arr[21000];
    double total_e = 0;
    double total_t = 0;

    // int key = -1;
    for (int i = 0; i < 20000; i++) {
        srand(time(nullptr));
        uniform_int_distribution<int> randint(0, i);
        int key = randint(rand_gen);

        key += rand() % 50;
        for (int j = 0; j < i; j++) {
            int num = randint(rand_gen);
            num += rand() % 50;
            arr[j] = num;
        }
        // sort(arr, i + 1); for bin

        auto start = std::chrono::high_resolution_clock::now();
        // bsearch(key, arr, i);
        int val = lsearch(key, arr, i+1);
        // int val = bsearch2(key, arr, 0, i + 1);
        auto finish = std::chrono::high_resolution_clock::now();
        int64_t dur = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count();
        // if (val == -1) {
        //     t.push_back(dur);
        //     elements.push_back(i);
        // }
        t.push_back(dur);
        elements.push_back(i);
        total_t += dur;
        ++total_e;
        // cout << key << ": " << arr[0] << endl;
    }
    plt::title("Linear search: elements (n) vs. time (ns)");
    plt::xlabel("elements (n)");
    plt::ylabel("time (ns)");
    cout << "avg (element/s): " << fixed << total_e / (total_t / pow(10, 9)) << endl;
    // plt::plot(elements, t);
    plt::scatter(elements, t);
    plt::show();
}