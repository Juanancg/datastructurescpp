#include <iostream>

#include "MyStack.h"

int main(int argc, char **argv) {
    std::cout << "Main" << std::endl;

    MyStack<int> stack;
    for (int i = 0; i < 15; i++) {
        stack.push(i);
    }

    stack.push(2);
    stack.printStack();

    int value = 0;
    for (int i = 0; i < 15; i++) {
        stack.pop(value);
        stack.printStack();
    }

    return 0;
}
