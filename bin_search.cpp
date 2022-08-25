#include <iostream>
using namespace std;

class Stack {
   private:
    static const int max_len = 20;
    int arr[max_len];
    int index;

   public:
    Stack() {
        index = 0;
    }

    bool push(int num) {
        if (index != max_len)
            arr[index++] = num;
        return index != max_len;
    }

    int get(int index) {
        if (index > this->index) {
            throw;
        }
        return arr[index];
    }

    int pop() {
        if (index == 0)
            throw;
        return arr[index--];
    }

    void sort() {
        for (int i = 0; i < index; i++) {
            for (int j = 0; j < index; j++) {
                if (arr[j] < arr[i]) {
                    int tmp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = tmp;
                }
            }
        }
    }

    // int search(int key) {
    //     int mid = index / 2;
    //     int count = 0;
    //     while (count < mid + 1) {
    //         ++count;
    //         if (arr[mid] > key) {
    //             --mid;
    //             continue;
    //         }
    //         if (arr[mid] < key) {
    //             ++mid;
    //             continue;
    //         }
    //         return mid;
    //     }
    //     return -1;
    // }

    int search(int key) {
        int mid = index / 2;
        int count = 0;
        while (count++ < mid + 1) {
            cout << mid << endl;
            if (arr[mid] < key) {
                mid /= 2;
                continue;
            }
            if (arr[mid] > key) {
                mid += mid / 2;
                continue;
            }
            return mid;
        }
        return -1;
    }
};

int main() {
    srand(time(nullptr));
    Stack st;
    for (int i = 0; i < 15; i++) {
        st.push(i * i);
    }
    int key = rand() % 15 * 15 + 1;
    int index = st.search(key);
    cout << "key: " << key << " is at " << index << endl;
    return 0;
}