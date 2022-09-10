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

class stack {
   private:
    node* top;
    int count;

   public:
    stack() {
        count = 0;
    }
    ~stack() {
        while (top) {
            node* g = top;
            top = top->p_pointer;
            delete g;
        }
    }

    int push(int num) {
        if (!count) {
            top = new node();
            top->value = num;
            ++count;
            return num;
        }
        top = new node(top);
        top->value = num;
        ++count;
        return num;
    }

    int pop() {
        if (is_empty()) {
            cout << "pointing to null" << endl;
            abort();
        }
        int num = top->value;
        node* g = top;
        top = top->p_pointer;
        delete g;
        --count;
        return num;
    }

    bool is_empty() {
        return top == nullptr;
    }

    void print() {
        cout << "[";
        for (node* n = top; n != nullptr; n = n->p_pointer) {
            cout << n->value << ", ";
        }
        cout << "]" << endl;
    }
};

int main() {
    stack* s = new stack();
    s->push(10);
    s->push(15);
    s->push(20);
    s->push(25);
    s->print();
    s->pop();
    s->pop();
    s->print();
    return 0;
}