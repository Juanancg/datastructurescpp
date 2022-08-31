#ifndef LINKEDLIST_H
#define LINKEDLIST_H

/*
    Quickie implementation of a Linked List for exercises
*/

template <typename T>
struct Node {
    T value;
    Node<T> *next = nullptr;
};

template <typename T>
class LinkedList {
   public:
    LinkedList() {
        first_ = new Node<T>;
        tail_ = new Node<T>;

        first_->next = nullptr;
        tail_->next = nullptr;

        num_elems_ = 0;
    }

    ~LinkedList() {
        clear();
    }

    int getSize() const {
        return num_elems_;
    }

    bool isEmpty() const {
        return getSize() == 0;
    }

    void clear() {
    }

    void push_front(const T new_data) {
        Node<T> *node_to_insrt = new Node<T>;
        node_to_insrt->value = new_data;

        if (!isEmpty()) {
            node_to_insrt->next = first_;
            first_ = node_to_insrt;

        } else {
            // Use first_ to add the new data
            node_to_insrt->next = first_->next;
            first_ = node_to_insrt;
            tail_ = first_;
        }

        num_elems_++;
    }

    void push_back(const T new_data) {
        if (!isEmpty()) {
            push_back(new_data, tail_);
            tail_ = tail_->next;

        } else {
            // Use first to add the new data
            push_back(new_data, tail_);
            first_ = tail_->next;
            tail_ = tail_->next;
        }
    }

    void pop_back() {
    }

    void print_from_start() {
        Node<T> *aux;
        aux = first_;

        std::cout << "Linked List: ";

        while (aux != nullptr) {
            std::cout << aux->value << " ";
            aux = aux->next;
        }
        std::cout << " - Num Elems " << num_elems_ << std::endl;
    }

   private:
    void push_back(const T new_data, Node<T> *prev_node) {
        Node<T> *node_to_insrt = new Node<T>;
        node_to_insrt->value = new_data;

        node_to_insrt->next = prev_node->next;
        prev_node->next = node_to_insrt;

        num_elems_++;
    }

    void push_front(const T new_data, Node<T> **first) {
        Node<T> *node_to_insrt = new Node<T>;
        node_to_insrt->value = new_data;

        node_to_insrt->next = (*first)->next;
        *first = node_to_insrt;

        num_elems_++;
    }

    Node<T> *first_;
    Node<T> *tail_;
    int num_elems_;
};

#endif