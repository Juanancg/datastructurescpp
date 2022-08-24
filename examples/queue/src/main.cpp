#include <iostream>

#include "MyQueue.h"

int main(int argc, char **argv) {
    std::cout << "Main1" << std::endl;

    MyQueue<int> queue;

    // Insert 10 elements from 0 to 10 in the queue
    std::cout << std::endl
              << "Inserting 10 elements from 0 to 10 in the queue" << std::endl;
    for (int i = 0; i < 10; i++) {
        queue.insert(i);
        queue.printQueue();
        queue.printQueueInOrder();
    }

    // Insert the element 100
    std::cout << std::endl
              << "Inserting the element 100" << std::endl;
    queue.insert(100);
    queue.printQueue();
    queue.printQueueInOrder();

    // Dequeue all the elements to empty the queue
    int elem = 0;
    std::cout << "Dequeue " << std::boolalpha << queue.getElem(elem) << " -> " << elem << std::endl;
    queue.printQueueInOrder();
    std::cout << "Dequeue " << std::boolalpha << queue.getElem(elem) << " -> " << elem << std::endl;
    queue.printQueueInOrder();
    std::cout << "Dequeue " << std::boolalpha << queue.getElem(elem) << " -> " << elem << std::endl;
    queue.printQueueInOrder();
    std::cout << "Dequeue " << std::boolalpha << queue.getElem(elem) << " -> " << elem << std::endl;
    queue.printQueueInOrder();
    std::cout << "Dequeue " << std::boolalpha << queue.getElem(elem) << " -> " << elem << std::endl;
    queue.printQueueInOrder();
    std::cout << "Dequeue " << std::boolalpha << queue.getElem(elem) << " -> " << elem << std::endl;
    queue.printQueueInOrder();
    std::cout << "Dequeue " << std::boolalpha << queue.getElem(elem) << " -> " << elem << std::endl;
    queue.printQueueInOrder();
    std::cout << "Dequeue " << std::boolalpha << queue.getElem(elem) << " -> " << elem << std::endl;
    queue.printQueueInOrder();
    std::cout << "Dequeue " << std::boolalpha << queue.getElem(elem) << " -> " << elem << std::endl;
    queue.printQueueInOrder();
    std::cout << "Dequeue " << std::boolalpha << queue.getElem(elem) << " -> " << elem << std::endl;
    queue.printQueueInOrder();

    // Try to get an element when the queue is empty
    elem = 0;
    std::cout << "Dequeue " << std::boolalpha << queue.getElem(elem) << " -> " << elem << std::endl;
    queue.printQueueInOrder();

    queue.printQueue();
    queue.printQueueInOrder();

    // Insert 200 300 400 500 600 700 800 900
    for (int i = 2; i < 15; i++) {
        queue.insert(i * 100);
    }
    queue.printQueueInOrder();

    queue.insert(28);
    queue.printQueue();
    queue.insert(29);
    queue.printQueue();
    queue.printQueueInOrder();

    return 0;
}
