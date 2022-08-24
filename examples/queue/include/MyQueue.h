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
        container_[front_] = new_elem;
        increaseIdx(front_);

        if (numElems_ < container_.size()) {
            numElems_++;
        } else {
            int back_candidate = back_;
            increaseIdx(back_candidate);
            if (front_ == back_candidate) {
                back_ = back_candidate;
            }
        }
        // Debugging prints
        // std::cout << "After Insert " << new_elem << " -> front " << front_ << " back " << back_ << std::endl;
    }

    bool isEmpty() {
        return numElems_ == 0;
    }

    bool isFull() {
        return numElems_ == MAX_QUEUE_SIZE - 1;
    }

    bool getElem(T &elem) {
        bool achieved = false;

        if (0 < numElems_) {
            if (back_ < container_.size()) {
                elem = container_[back_];
                container_[back_] = 0;
                increaseIdx(back_);
                numElems_--;
                achieved = true;
            }
        }
        // Debugging prints
        // std::cout << "After Get Elem -> front " << front_ << " back " << back_ << std::endl;

        return achieved;
    }

    void printQueue() {
        if (!isEmpty()) {
            std::cout << "Queue: ";

            for (int i = 0; i < container_.size(); i++) {
                std::cout << container_[i] << " ";
            }
            std::cout << " - Num Elems " << numElems_ << std::endl;
        } else {
            std::cout << "Empty Queue" << std::endl;
        }
    }

    void printQueueInOrder() {
        if (!isEmpty()) {
            std::cout << "Queue Sorted: ";

            if (front_ < back_) {
                for (int i = back_; i < container_.size(); i++) {
                    std::cout << container_[i] << " ";
                }

                for (int i = 0; i < front_ && i < container_.size(); i++) {
                    std::cout << container_[i] << " ";
                }

            } else if (back_ < front_) {
                for (int i = back_; i < front_ && i < container_.size(); i++) {
                    std::cout << container_[i] << " ";
                }

            } else {
                for (int i = back_; i < numElems_ && i < container_.size(); i++) {
                    std::cout << container_[i] << " ";
                }

                if (container_.size() - back_ < numElems_) {
                    for (int i = 0; i < back_ && i < container_.size(); i++) {
                        std::cout << container_[i] << " ";
                    }
                }
            }

            std::cout << " - Num Elems " << numElems_ << std::endl;
        } else {
            std::cout << "Empty Queue" << std::endl;
        }
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
    int front_;  // Always address the next element
    int numElems_;
};

#endif  // MYQUEUE_H