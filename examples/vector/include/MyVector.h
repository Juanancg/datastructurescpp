#ifndef MYVECTOR_H
#define MYVECTOR_H

class MyVector {
   public:
    MyVector(int size = 0);
    ~MyVector();

    int size() const;
    void addElem(const int new_value);
    int getElem(const int index) const;
    void resize(const int new_size);
    bool isEmpty() const;
    int &operator[](const int index);

   private:
    void reserve(const int new_size);

    const int STARTING_SIZE = 5;

    int size_;       // Capacity
    int num_elems_;  // Size
    int *container_;
};

#endif