#include <iostream>

#include "MyQueue.h"

int main(int argc, char **argv) {
    std::cout << "Main" << std::endl;

    MyQueue<int> queue;

    for (int i = 0; i < 10; i++) {
        queue.insert(i);
        queue.printQueue();
    }

    queue.insert(100);
    queue.printQueue();
    for (int i = 0; i < 10; i++) {
        queue.insert(i * 100);
        queue.printQueue();
    }

    return 0;
}
