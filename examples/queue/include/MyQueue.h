#ifndef MYQUEUE_H
#define MYQUEUE_H

#include <array>
#include <iostream>

const int MAX_QUEUE_SIZE = 10;

template <typename T>
class MyQueue {
   public:
    MyQueue() {
        back_ = 0;
        front_ = 0;
        numElems_ = 0;
    }

    ~MyQueue() {}

    void insert(const T new_elem) {
        if (numElems_ < container_.size()) {
            container_[front_] = new_elem;
            front_++;
            numElems_++;
        } else {
            increaseIdx(front_);

            container_[front_] = new_elem;

            if (front_ == back_) {
                increaseIdx(back_);
            }
        }
        std::cout << "front " << front_ << " back " << back_ << std::endl;
    }

    bool isEmpty() {
        return numElems_ == 0;
    }

    bool isFull() {
        return numElems_ == MAX_QUEUE_SIZE - 1;
    }

    bool getElem(T &elem) {
    }

    void printQueue() {
        if (!isEmpty()) {
            for (int i = 0; i < numElems_ && i < container_.size(); i++) {
                std::cout << container_[i] << " ";
            }
            std::cout << std::endl;
        }
    }

    void printQueueInOrder() {
    }

    void clear() {
    }

   private:
    void increaseIdx(int &index) {
        if (MAX_QUEUE_SIZE <= index + 1) {
            index = 0;
        } else {
            index++;
        }
    }

    std::array<T, MAX_QUEUE_SIZE> container_;
    int back_;
    int front_;
    int numElems_;
};

#endif  // MYQUEUE_H