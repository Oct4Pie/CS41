#include <iostream>
using namespace std;

class node {
   public:
    int value;
    node* n_pointer;
    node(node* np) {
        this->n_pointer = np;
    }
    node(){};
};

class queue {
   private:
    node* last;
    node* first;
    int count;

   public:
    queue() {
        first = last = 0;
        count = 0;
    }
    ~queue() {
        while (last) {
            node* g = last;
            last = last->n_pointer;
            delete g;
        }
    }
    int enqueue(int val) {
        if (last == 0) {
            last = new node();
            last->value = val;
            first = last;
            ++count;
            return val;
        }

        first->n_pointer = new node();
        first = first->n_pointer;
        first->value = val;
        ++count;
        return val;
    }
    int dequeue() {
        if (is_empty()) {
            cout << "pointing to null" << endl;
            abort();
        }
        node* g = last;
        int val = last->value;
        last = last->n_pointer;
        delete g;
        --count;
        return val;
    }

    bool is_empty() {
        return count == 0;
    }

    void print() {
        node* np = last;
        cout << "[";
        while (np) {
            cout << np->value << ", ";
            np = np->n_pointer;
        }
        cout << "]" << endl;
    }
};

int main() {
    queue* q = new queue();
    q->enqueue(10);
    q->enqueue(15);
    q->enqueue(20);
    q->print();
    q->dequeue();
    q->dequeue();
    q->print();
}
