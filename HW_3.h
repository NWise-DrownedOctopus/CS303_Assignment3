//
// Created by nicho on 4/8/2025.
//

#ifndef HW_3_H
#define HW_3_H

using namespace std;
#include <iostream>
#include <vector>

template <typename Item_Type>
class Queue {
public:
    Queue();
    ~Queue();
    int num_items = 0;
    struct Node {
        Item_Type data;
        Node* next;
        Node(Item_Type value) : data(value), next(nullptr) {}
    };
    Node* head{};
    Node* tail{};
    void push(Item_Type value);
    void pop_front();
    void move_to_rear();
    Item_Type front();
    bool empty();
    int size();
};

template <typename Item_Type>
Queue<Item_Type> :: Queue() {
    head = nullptr;
    tail = nullptr;
}

template <typename Item_Type>
Queue<Item_Type>::~Queue() {
    while (!empty()) {
        pop_front();
    }
}
template <typename Item_Type>
void Queue<Item_Type>::push(Item_Type value) {
    if (head == nullptr) {
        head = new Node(value);
        tail = head;
        num_items++;
        return;
    }
    Node* new_node = new Node(value);
    tail->next = new_node;
    tail = new_node;
    num_items++;
}

template<typename Item_Type>
void Queue<Item_Type>::pop_front() {
    if (head == nullptr) {
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
    num_items--;

    if (head == nullptr) {
        tail = nullptr;
    }
}

template<typename Item_Type>
void Queue<Item_Type>::move_to_rear() {
    if (empty() || head->next == nullptr) {
        return;
    }

    Item_Type front_item = front(); // Save the value
    pop_front();                    // Remove the front node
    Node* new_node = new Node(front_item);
    tail->next = new_node;
    tail = new_node;
}

template<typename Item_Type>
Item_Type Queue<Item_Type>::front() {
    if (empty()) {
        throw std::runtime_error("Attempted to access front of empty queue");
    }
    return head->data;
}


template<typename Item_Type>
bool Queue<Item_Type>::empty() {
    return head == nullptr;
}

template<typename Item_Type>
int Queue<Item_Type>::size() {
    return num_items;
}

//  Linear search function with a recursive step that finds the last
//  occurrence of a target in a vector. Here I am starting from the rear
template<typename Item_Type>
int last_occurrence_helper(const vector<Item_Type>& vec, const Item_Type& item, int index) {
    // Here we exit if we have checked all index already
    if (index < 0) {
        return -1;
    }
    if (vec[index] == item) {
        return index; // Found the last occurrence (working backward)
    }
    return last_occurrence_helper(vec, item, index - 1); // Recurse toward front
}

template<typename Item_Type>
int last_occurrence(const std::vector<Item_Type>& vec, const Item_Type& item) {
    return last_occurrence_helper(vec, item, vec.size() - 1);
}

void Q_insertion_sort(Queue<int>& q);

#endif //HW_3_H
