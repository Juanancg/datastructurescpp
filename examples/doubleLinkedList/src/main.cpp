#include <iostream>

#include "DoubleLinkedList.h"

void changetest(int **ptr2, int *ptr1) {
    std::cout << "Inside" << std::endl;
    *ptr2 = ptr1;
    std::cout << "Inside funct " << *ptr2 << " - " << ptr1 << std::endl;
}

int main(int argc, char **argv) {
    int *ptrtoptr;
    int *ptr;
    int a = 5;
    ptr = &a;

    std::cout << "ptr2ptr " << ptrtoptr << std::endl;
    std::cout << "ptrsingle " << ptr << std::endl;
    changetest(&ptrtoptr, ptr);
    std::cout << "ptr2ptr " << ptrtoptr << " " << *ptrtoptr << std::endl;
    std::cout << "ptrsingle " << ptr << std::endl;

    std::cout << "DoubleLinkedList in cpp" << std::endl;

    DoubleLinkedList<int> list;

    std::cout << "Fill the list" << std::endl;
    for (int i = 1; i < 10; i++)
        list.push_back(i);
    list.print_from_start();
    std::cout << std::endl;

    std::cout << "Clearing the list!" << std::endl;
    list.clear();
    list.print_from_start();
    std::cout << std::endl;

    for (int i = 1; i < 15; i++)
        list.push_back(i * 2);

    list.print_from_start();

    std::cout << std::endl
              << "Let's find the value 11" << std::endl;
    list.find(11);

    std::cout << std::endl
              << "Try to find the value 16" << std::endl;
    list.find(16);

    std::cout << std::endl
              << "Then remove it" << std::endl;
    list.remove(16);
    list.print_from_start();

    std::cout << std::endl
              << "What if I remove the last one?" << std::endl;
    list.remove(28);
    list.print_from_start();

    std::cout << std::endl
              << "What if I remove the last one" << std::endl;
    list.remove(28);
    list.print_from_start();

    return 0;
}
