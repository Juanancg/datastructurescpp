#include <iostream>

#include "MyVector.h"

int main(int argc, char **argv) {
    std::cout << "Main" << std::endl;

    MyVector vec0(5);
    std::cout << vec0.size() << std::endl;
    for (int i = 0; i < 15; i++) {
        vec0.addElem(i);
    }
    std::cout << vec0.size() << std::endl;

    for (int i = 0; i < vec0.size(); i++) {
        std::cout << vec0.getElem(i) << " ";
    }

    std::cout << std::endl;

    return 0;
}
