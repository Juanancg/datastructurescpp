#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

template <typename T>
struct Node {
    T value;
    Node<T> *next = nullptr;
    Node<T> *prev = nullptr;
};

template <typename T>
class DoubleLinkedList {
   public:
    DoubleLinkedList() {
        first_ = new Node<T>;
        tail_ = new Node<T>;

        first_->next = tail_;
        tail_->prev = first_;

        num_elems_ = 0;
    }

    ~DoubleLinkedList() {
        clear();
    }

    int getSize() const {
        return num_elems_;
    }

    bool isEmpty() const {
        return getSize() == 0;
    }

    void clear() {
        while (!isEmpty()) {
            pop_back();
        }
    }

    void push_front(const T new_data) {
        if (isEmpty()) {
            // If the list is empty, we can take adventage of the first one to save the data
            first_->value = new_data;
            num_elems_++;
        } else {
            insert(first_->value, first_);
            first_->value = new_data;
            first_->prev = nullptr;
        }
    }

    void pop_front();

    void push_back(const T new_data) {
        if (isEmpty()) {
            // If the list is empty, we can take adventage of the first one to save the data
            first_->value = new_data;
            num_elems_++;
        } else {
            insert(new_data, tail_->prev);
        }
    }

    void pop_back() {
        if (!isEmpty()) {
            // This if is to reset the first element without loosing the pointer to the first element
            if (1 < num_elems_) {
                tail_->prev = tail_->prev->prev;

                // Delete tail node
                tail_->prev->next = nullptr;
                delete tail_->prev->next;

                // The new tail one should point to tail
                tail_->prev->next = tail_;
            } else {
                first_->value = T();
            }
            num_elems_--;
        }
    }

    bool remove(const T value_to_rm) {
        bool success = false;
        Node<T> *node_to_rm;
        if (find(value_to_rm, &node_to_rm)) {
            // std::cout << "To remove ptr " << node_to_rm << " " << node_to_rm->value << std::endl;
            node_to_rm->prev->next = node_to_rm->next;
            node_to_rm->next->prev = node_to_rm->prev;

            node_to_rm->next = nullptr;
            node_to_rm->prev = nullptr;
            delete node_to_rm;
            num_elems_--;
            std::cout << "Element removed" << std::endl;
            success = true;
        }

        return success;
    }

    bool find(const T value_to_find) {
        Node<T> *node_found;
        return find(value_to_find, &node_found);
    }

    bool find(const T value_to_find, Node<T> **node_found) {
        bool found = false;
        if (!isEmpty()) {
            if (first_->value != value_to_find) {
                found = find_recursive(first_->next, value_to_find, node_found);
            } else {
                std::cout << "Value found! " << first_->value << std::endl;
                node_found = &first_;
                found = true;
            }
        } else {
            std::cout << "The List is empty!" << std::endl;
        }
        return found;
    }

    void print_from_start() {
        if (!isEmpty()) {
            print_recursive(first_);
            std::cout << " - Num Elems " << num_elems_ << std::endl;
        } else {
            std::cout << "The List is empty!" << std::endl;
        }
    }

   private:
    bool print_recursive(const Node<T> *node) {
        std::cout << node->value << " ";
        if (node->next != nullptr && node->next->next != nullptr) {
            return print_recursive(node->next);
        } else {
            return false;
        }
    }

    bool find_recursive(Node<T> *node, const T elem_to_find, Node<T> **node_found) {
        bool found = false;

        if (node->value != elem_to_find) {
            if (node->next != nullptr) {
                return find_recursive(node->next, elem_to_find, node_found);
            } else {
                std::cout << "End of the list reached. Value not found" << std::endl;
            }
        } else {
            std::cout << "Value found! " << node->value << " - " << node << std::endl;
            *node_found = node;
            std::cout << *node_found << " = " << node << std::endl;
            found = true;
        }

        return found;
    }

    void insert(const T new_data, Node<T> *prev_node) {
        Node<T> *node_to_insrt = new Node<T>;
        node_to_insrt->value = new_data;

        // 1 new node should point to the prev.next
        node_to_insrt->next = prev_node->next;  // If nullptr is ok!

        // 2 if prev.next isnt nullptr, should point to the new one
        if (prev_node->next != nullptr) {
            prev_node->next->prev = node_to_insrt;
        }

        // 3 new node prev should point to the prev_node
        node_to_insrt->prev = prev_node;

        // 4 prev_node.next to the new one
        prev_node->next = node_to_insrt;

        num_elems_++;
    }

    Node<T> *first_;
    Node<T> *tail_;
    int num_elems_;
};

#endif