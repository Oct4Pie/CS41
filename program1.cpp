#include <iostream>
#include <string>
using namespace std;

class node {
   public:
    float value;
    node* p_pointer;
    node(node* pp) { this->p_pointer = pp; }
    node(){};
};

class stack {
   public:
    node* top;
    int count;
    stack() { count = 0; }
    ~stack() { // free memory
        while (top) {
            node* g = top;
            top = top->p_pointer;
            delete g;
        }
    }

    int push(float num) {
        ++count;
        if (!count) {
            top = new node();
            top->value = num;
            return num;
        }
        top = new node(top); // each new node points to previous
        top->value = num;
        return num;
    }

    float pop() {
        if (is_empty()) { // prevent seg fault
            cout << "pop(): Error: pointing to null" << endl;
            abort();
        }
        float num = top->value;
        node* g = top;
        top = top->p_pointer;
        delete g;
        --count;
        return num;
    }

    bool is_empty() { return top == nullptr; }
};
// go through the expression and count
void validate(string inp, string ops) {
    if (inp.at(inp.length() - 1) != '=') {
        cout << "exression does not end with '='" << endl;
        abort();
    }
    int ssf = 0, ssc = 0;
    for (int i = 0; i < inp.length(); i++) {
        if (inp.at(i) == ' ') {
            continue;
        }
        float ii = atof(&inp.at(i));
        if (ii) {
            string si;
            while (i < inp.length() && inp.at(i) != ' ') {
                si += inp.at(i++);
            }
            ++ssf;

        } else if (inp.at(i) == '0') {
            ++ssf;  // because atof for
        } else if (ops.find(inp.at(i)) < ops.length()) {
            ++ssc;
        }
    }  // there is a problem when num of operands is not equal to opertors +1
    if ((ssc + 1) > ssf) {
        cout << "Error: too many operators" << endl;
        abort();
    }
    if ((ssc + 1) < ssf) {
        cout << "Error: too many operands" << endl;
        abort();
    }
}

int main() {
    stack* sf = new stack();
    string ops = "*/-+";
    string inp;
    while (1) {
        cout << "please enter a reverse polish expression terminated by a '=':" << endl;
        getline(cin, inp);
        if (inp == "0") {
            return 0;
        }
        validate(inp, ops);
        for (int i = 0; i < inp.length(); i++) {
            if (inp.at(i) == ' ') {  // jump over spaces
                continue;
            }
            float ii = atof(&inp.at(i));
            if (ii) {
                string si;
                while (i < inp.length() && inp.at(i) != ' ') {
                    si += inp.at(i++);
                }
                sf->push(atof(si.c_str()));

            } else if (inp.at(i) == '0') {  // care for atof(char *) for '0'
                sf->push(0);
            } else if (ops.find(inp.at(i)) < ops.length()) {  // push valid operators
                if (inp.at(i) == '/') {
                    float d = sf->pop(), n = sf->pop();
                    if (d == 0) {  // check for division by 0
                        cout << "Error: Division by zero: " << n << "/" << 0 << endl;
                        return -1;
                    }
                    sf->push(n / d);
                }
                if (inp.at(i) == '+') {
                    sf->push(sf->pop() + sf->pop());
                }
                if (inp.at(i) == '-') {
                    sf->push(-(sf->pop() - sf->pop()));
                }
                if (inp.at(i) == '*') {
                    sf->push(sf->pop() * sf->pop());
                }  // watch for stack order
            }
        }
        cout << inp << " " << sf->pop() << endl;
    }
}

/*
    [m3hdi@0x0003ef2c527 CS 41 (main ✗)]$ ./program1
    please enter a reverse polish expression terminated by a '=':
    10 15 + =
    10 15 + = 25
    please enter a reverse polish expression terminated by a '=':
    10 15 - =
    10 15 - = -5
    please enter a reverse polish expression terminated by a '=':
    2.5 3.5 + =
    2.5 3.5 + = 6
    please enter a reverse polish expression terminated by a '=':
    10 0 / =
    Error: Division by zero: 10/0
    [m3hdi@0x0003ef2c527 CS 41 (main ✗)]$ ./program1
    please enter a reverse polish expression terminated by a '=':
    10 20 * / =
    Error: too many operators
    [1]    28971 abort      ./program1
    [m3hdi@0x0003ef2c527 CS 41 (main ✗)]$ ./program1
    please enter a reverse polish expression terminated by a '=':
    12 20 30 / =
    Error: too many operands
    [1]    28987 abort      ./program1
    [m3hdi@0x0003ef2c527 CS 41 (main ✗)]$ ./program1
    please enter a reverse polish expression terminated by a '=':
    -10 -30 - =
    -10 -30 - = 20
    please enter a reverse polish expression terminated by a '=':
    100 10 50 25 / * - -2 / =
    100 10 50 25 / * - -2 / = -40
    please enter a reverse polish expression terminated by a '=':
    100 10 50 25 / * - -2 /
    exression does not end with '='
    [1]    29005 abort      ./program1
    [m3hdi@0x0003ef2c527 CS 41 (main ✗)]$ ./program1
    please enter a reverse polish expression terminated by a '=':
    10 34 17 2 * - /
    exression does not end with '='
    [1]    29030 abort      ./program1
    [m3hdi@0x0003ef2c527 CS 41 (main ✗)]$ ./program1
    please enter a reverse polish expression terminated by a '=':
    10 34 17 2 * - / =
    Error: Division by zero: 10/0
    [m3hdi@0x0003ef2c527 CS 41 (main ✗)]$
*/