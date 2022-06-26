#ifndef MYSTACK_H
#define MYSTACK_H

#include <array>
#include <iostream>

const int MAX_SIZE_STACK = 10;

template <typename T>
class MyStack {
   public:
    MyStack() {
        top_ = -1;
    }
    ~MyStack() {}

    bool pop(T &value) {
        bool toret = false;
        if (!isEmpty()) {
            value = container_[top_];
            top_--;
            toret = true;
        } else {
            std::cout << "Warning, empty stack " << top_ << std::endl;
        }

        return toret;
    }

    void push(const T new_elem) {
        if (top_ < MAX_SIZE_STACK - 1) {
            top_++;
            container_[top_] = new_elem;
        } else {
            std::cout << "Stack Overflow, pop data to insert new ones" << std::endl;
        }
    }

    bool isEmpty() const {
        return top_ == -1;
    }

    void printStack() {
        if (!isEmpty()) {
            for (int i = 0; i < (top_ + 1) && i < container_.size(); i++) {
                std::cout << container_[i] << " ";
            }
            std::cout << std::endl;
        }
    }

   private:
    std::array<T, MAX_SIZE_STACK> container_;
    int top_;
};

#endif  // MYSTACK_H