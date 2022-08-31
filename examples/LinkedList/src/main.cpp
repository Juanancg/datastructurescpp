#include <iostream>

#include "LinkedList.h"

int main(int argc, char **argv) {
    std::cout << "LinkedList in cpp" << std::endl;

    LinkedList<int> list;

    std::cout << "Pushing back the list:" << std::endl;
    for (int i = 0; i < 10; i++)
        list.push_back(i);
    list.print_from_start();
    std::cout << std::endl;

    std::cout << "Pushing front the list:" << std::endl;
    for (int i = 0; i < 10; i++) {
        list.push_front(i);
    }
    std::cout << std::endl;
    list.print_from_start();
    std::cout << std::endl;

    // Exercise 1: Merge two sorted linked list
    std::cout << std::endl
              << "Get ready for merging two sorted linked List" << std::endl;

    return 0;
}
