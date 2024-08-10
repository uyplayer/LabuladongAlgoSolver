//
// Created by uyplayer on 2024-08-10.
//



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
            tail = nullptr;
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

    T front() const {
        if (head == nullptr) {
            throw std::runtime_error("链表是空的");
        }
        return head->data;
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
    std::cout << "用链表实现队列-栈" << std::endl;

    LinkedList<int> list;

    // 添加一些值
    list.add_value(10);
    list.add_value(20);
    list.add_value(30);

    // 打印链表
    std::cout << "链表内容: ";
    list.print_list();  // 输出: 10 20 30

    // 访问头部元素
    try {
        std::cout << "链表头部元素: " << list.front() << std::endl;  // 输出: 10
    } catch (const std::runtime_error &e) {
        std::cerr << "错误: " << e.what() << std::endl;
    }

    // 弹出头部元素
    list.pop_head();
    std::cout << "删除头部元素后链表内容: ";
    list.print_list();  // 输出: 20 30

    // 弹出尾部元素
    list.pop_tail();
    std::cout << "删除尾部元素后链表内容: ";
    list.print_list();  // 输出: 20

    // 再次弹出头部元素
    list.pop_head();
    std::cout << "删除头部元素后链表内容: ";
    list.print_list();  // 输出: (链表为空)

    try {
        std::cout << "链表头部元素: " << list.front() << std::endl;
    } catch (const std::runtime_error &e) {
        std::cerr << "错误: " << e.what() << std::endl;
    }

    return 0;
}
