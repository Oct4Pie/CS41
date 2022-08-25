#include <iostream>

class Array {
   private:
    const static int max_size = 10;
    int stack[max_size];
    int count;

   public:
    Array() {
        count = 0;
    };

    void push(int num) {
        if (count == max_size) {
            std::cout << "the stack is full" << std::endl;
            return;
        }
        stack[count] = num;
        ++count;
    };

    bool is_empty() {
        return count == 0;
    }

    int pop() {
        if (is_empty()) {
            std::cout << "the stack is empty" << std::endl;
            throw;
        }

        return stack[--count];
    }
};

int main() {
    Array arr;
    for (int i = 0; i < 5; i++) {
        arr.push(i * i);
    }
    int last = arr.pop();
    std::cout << last << std::endl;

    // error
    for (int i = 0; i < 10; i++) {
        arr.push(i * i);
    }

    for (int i = 0; i < 4; i++) {
        std::cout << arr.pop() << std::endl;
    }

    // exception
    last = arr.pop();
}