#include <iostream>

template<typename T>
struct Node {
    T data;
    Node *next;

    explicit Node(T value) : data(value), next(nullptr) {
    }
};

template<typename T>
class LinkedList {
public:
    LinkedList() : head(nullptr) ,tail(nullptr){
    }

    ~LinkedList() {
        clear();
    }

    void add_value(T value) {
        auto *new_node = new Node<T>(value);
        if (head == nullptr) {
            head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
    }

    void print_list() const {
        auto current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    void pop_head() {
        if (head == nullptr) {
            return;
        }
        auto current = head->next;
        delete head;
        head = current;
    }

    void pop_tail() {
        if (head == nullptr) {
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            tail= nullptr;
            return;
        }

        auto current = head;
        while (current->next->next != nullptr) {
            current = current->next;
        }
        delete current->next;
        current->next = nullptr;
        tail = current;
    }
private:
    void clear() {
        Node<T> *current = head;
        while (current) {
            Node<T> *next = current->next;
            delete current;
            current = next;
        }
        // 删除 head,tail
        head = nullptr;
        tail = nullptr;
    }

private:
    Node<T> *head;
    Node<T> *tail;
};

int main() {
    LinkedList<int> list;
    list.add_value(1);
    list.add_value(2);
    list.add_value(3);
    list.add_value(4);
    list.add_value(5);
    list.print_list();
    list.pop_head();
    list.print_list();
    list.pop_tail();
    list.print_list();
    list.add_value(1);
    list.add_value(2);
    list.add_value(3);
    list.add_value(4);
    list.add_value(5);
    list.print_list();
    return 0;
}
