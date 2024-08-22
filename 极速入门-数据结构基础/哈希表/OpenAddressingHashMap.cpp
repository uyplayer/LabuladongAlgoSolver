//
// Created by uyplayer on 2024-08-21.
//



#include <iostream>
#include <vector>

class ExampleLinearProbingHashMap {

private:
    struct Node {
        int key;
        int value;

        Node(int key, int value) : key(key), value(value) {};
    };

    std::vector<Node *> table;

public:
    explicit ExampleLinearProbingHashMap(int capacity) {
        table.resize(capacity);
    }

    int findKeyIndex(int key) {
        auto index = hash(key);

        while (table[index] != NULL) {
            if (table[index]->key == key) {
                return index;
            }
            index = (index + 1) % table.size();
        }

        return index;
    }

    int hash(int key) {
        return key % table.size();
    }

    void put(int key, int value) {
        int index = findKeyIndex(key);
        table[index] = new Node(key, value);
    }

    int get(int key) {
        int index = findKeyIndex(key);
        return table[index] == nullptr ? -1 : table[index]->val;
    }

    void remove(int key) {
        auto index = findKeyIndex(key);
        if (table[index] == nullptr) {
            return;
        }

        table[index] = nullptr;
        index = (index + 1) % table.size();
        while (table[index] != nullptr) {
            auto entry = table[index];
            table[index] = nullptr;
            put(entry->key, entry->val);
            index = (index + 1) % table.size();

        }


    }


};