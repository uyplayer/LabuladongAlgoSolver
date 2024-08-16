//
// Created by uyplayer on 2024-08-14.
//


#include <iostream>
#include <stdexcept>





template<typename T>
class LinkedListDeque {
private:
    struct Node {
        T value;
        Node* prev;
        Node* next;
        explicit Node(T val):value(val),prev(nullptr),next(nullptr){};

    };

    Node* head;
    Node* tail;
    size_t size;


public:
    LinkedListDeque() : head(nullptr), tail(nullptr), size(0) {};
     ~LinkedListDeque() {
        clear();
    }
    void addFirst(T value){
         Node* newNode = new Node(value);
        if (head == nullptr){
            head = tail = newNode;
        } else {
             newNode->next = head;
             head->prev = newNode;
              head = newNode;
        }
         ++size;
     }

     void addLast(T value){
         Node* newNode = new Node(value);
          if (tail == nullptr) {  // Empty deque
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        ++size;

     }

      T removeFirst() {
        if (isEmpty()) {
            throw std::out_of_range("Deque is empty");
        }
        Node* oldHead = head;
        T value = head->value;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete oldHead;
        --size;
        return value;
    }
    T removeLast() {
        if (isEmpty()) {
            throw std::out_of_range("Deque is empty");
        }
        Node* oldTail = tail;
        T value = tail->value;
        tail = tail->prev;
        if (tail != nullptr) {
            tail->next = nullptr;
        } else {  // The deque is now empty
            head = nullptr;
        }
        delete oldTail;
        --size;
        return value;
    }

    bool isEmpty() const {
        return size == 0;
    }

    size_t getSize() const {
        return size;
    }


    void clear() {
        while (!isEmpty()) {
            removeFirst();
        }
    }


    void printDeque() const {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->value << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

};