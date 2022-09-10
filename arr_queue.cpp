#include <iostream>
using namespace std;

class node {
   public:
    int value;
    node* p_pointer;
    node(node* pp) {
        this->p_pointer = pp;
    }
    node(){};
};

class arrayq {
   private:
    static const int max_size = 10;
    int count;
    node items[max_size], front, back;

   public:
    arrayq() {
        count = 0;
    }
    int enqueue(int num) {
        if (count == max_size) {
            cout << "max size reached";
            abort();
        }
        for (int i = count; i >= 0; i--) {
            items[i+1] = items[i];
        }
        items[0].value = num;
        ++count;
        return num;
    }

    int dequeue() {
        if (is_empty()) {
            cout << "empty array" << endl;
            abort();
        }
        --count;
        return items[count + 1].value;
    }

    bool is_empty() {
        return count == 0;
    }

    void print() {
        cout << "[";
        for (int i = 0; i < count; i++) {
            cout << items[i].value << ", ";
        }
        cout << "]" << endl;
    }
};

int main() {
    arrayq* a = new arrayq();
    a->enqueue(10);
    a->enqueue(15);
    a->enqueue(20);
    a->enqueue(25);
    a->print();
    a->dequeue();
    a->dequeue();
    a->print();
    return 0;
}