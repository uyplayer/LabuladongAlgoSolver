//
// Created by uyplayer on 2024-08-22.
//


#include <iostream>
#include <vector>


class LinearProbingHashMap {

private:
    struct Node {
        int key;
        int value;

        Node(int k, int v) : key(k), value(v) {}
    };

    std::vector<Node *> table;
    int capacity;
    int size;

    int hash(int kye) const {
        return kye % capacity;
    }

public:

    explicit LinearProbingHashMap(int capacity) : capacity(capacity), size(0) {
        table.resize(capacity, nullptr);
    };

    void put(int key, int value) {
        if (size == capacity) {
            std::cout << "Hash table is full!" << std::endl;
            return;
        }
        int index = hash(key);
        while (table[index] != nullptr && table[index]->key != key) {
            index = (index + 1) % capacity;
        }
        // 找到空位置
        if (table[index] == nullptr) {
            table[index] = new Node(key, value);
            size++;
        } else {
            // 如果找到的键相同，更新值
            table[index]->value = value;
        }
    }

    int get(int key) {
        int index = hash(key);
        while (table[index] != nullptr) {
            if (table[index]->key == key) {
                return table[index]->value;
            }
            // 找下一个位置
            index = (index + 1) % capacity;
        }
        return -1;
    }

    void remove(int key) {
        int index = hash(key);
        while (table[index] != nullptr) {
            if (table[index]->key == key) {
                delete table[index];
                table[index] = nullptr;
                size--;
                // 重新探测后续的位置，重新放置这些元素
                index = (index + 1) % capacity;
                while (table[index] != nullptr) {
                    Node *tmp = table[index];
                    table[index] = nullptr;
                    size--;
                    put(temp->key, temp->value);
                    delete temp;
                    index = (index + 1) % capacity;
                }
                return;

            }
            index = (index + 1) % capacity;
        }
    }
};