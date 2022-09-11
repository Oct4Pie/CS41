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

class Sorted {
   private:
    node* first;
    node* last;
    node* current;
    int count;

   public:
    Sorted() {
        first = last = 0;
        count = 0;
    }

    ~Sorted() {
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
        node* n = last;
        node* np = last->n_pointer;  // start from index 1
        // check for index 0 for speed
        if (n->value > val) {
            node* p = new node();
            p->value = val;
            p->n_pointer = n;
            last = p;
            return val;
        }
        // list is technically sorted with length 1
        while (np) {
            if (np->value > val) {
                node* p = new node();
                p->value = val;
                p->n_pointer = np;
                n->n_pointer = p;
                return val;
            }
            n = np;
            np = np->n_pointer;
        }
        // add to end when equal or bigger
        first->n_pointer = new node();
        first = first->n_pointer;
        first->value = val;
        ++count;
        return val;
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
    int num;
    Sorted* s = new Sorted();
    cout << "please enter integers:" << endl;
    while (cin >> num) {
        if (num == -1) {
            break;
        }
        s->enqueue(num);
        s->print();
    }
}

/*
please enter integers:
1
[1, ]
7
[1, 7, ]
11
[1, 7, 11, ]
2
[1, 2, 7, 11, ]
5
[1, 2, 5, 7, 11, ]
8
[1, 2, 5, 7, 8, 11, ]
9
[1, 2, 5, 7, 8, 9, 11, ]
-5
[-5, 1, 2, 5, 7, 8, 9, 11, ]
-3
[-5, -3, 1, 2, 5, 7, 8, 9, 11, ]
15
[-5, -3, 1, 2, 5, 7, 8, 9, 11, 15, ]
*/