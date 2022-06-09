#include "MyVector.h"

#include <algorithm>

MyVector::MyVector(int size) : size_(size + STARTING_SIZE) {
    num_elems_ = 0;
    container_ = new int[size_];
}

MyVector::~MyVector() {
    delete[] container_;
}

int& MyVector::operator[](const int index) { return container_[index]; }

int MyVector::size() const { return num_elems_; }

void MyVector::addElem(const int new_value) {
    if (size_ == num_elems_) {
        reserve(size_ + STARTING_SIZE);
    }
    container_[num_elems_] = new_value;
    num_elems_++;
}

int MyVector::getElem(const int index) const {
    int toret = -1;

    if (index < num_elems_) {
        toret = container_[index];
    }
    return toret;
}

void MyVector::resize(const int new_size) {}

bool MyVector::isEmpty() const { return (num_elems_ == 0); }

void MyVector::reserve(const int new_size) {
    if (size_ < new_size) {
        int* new_vector = new int[new_size];

        // Copy the data of the previous array into the new one
        for (int i = 0; i < num_elems_; i++) {
            new_vector[i] = container_[i];
        }

        delete[] container_;
        container_ = new_vector;

        size_ = new_size;
    }
}
