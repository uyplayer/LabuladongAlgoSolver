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
        return table[index] == nullptr ? -1 : table[index]->value;
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
            put(entry->key, entry->value);
            index = (index + 1) % table.size();

        }


    }


};


class ExampleLinearProbingHashMapSymbol {
private:
    struct Node {
        int key;
        int value;

        Node(int key, int value) : key(key), value(value) {};
    };

    Node *DELETED = new Node{-2, -2};
    std::vector<Node *> table;

    int hash(int key) {
        return key / table.size();
    }

    int findKeyIndex(int key) {

        for (int i = hash(key), step = 0; table[i] != nullptr; i = (i + 1) % table.size()) {
            if (table[i] == DELETED) continue;
            if (table[i]->key == key) return i;
            if (++step == table.size()) return -1;
        }

        return -1;

    }
public:
     explicit ExampleLinearProbingHashMapSymbol(int initCapacity) {
        table.resize(initCapacity, nullptr);
    }

    // 增/改
    void put(int key, int val) {
        int index = findKeyIndex(key);

        if (index != -1 && table[index] != nullptr) {
            table[index]->value = val;
            return;
        }

        Node* node = new Node{key, val};
        index = hash(key);
        while (table[index] != nullptr && table[index] != DELETED) {
            index = (index+1) % table.size();
        }
        table[index] = node;
    }


    void remove(int key) {
        int index = findKeyIndex(key);

        if (index == -1) return;
        // 直接用占位符表示删除
        table[index] = DELETED;
    }

    int get(int key) {
        int index = findKeyIndex(key);
        return (index != -1) ? table[index]->value : -1;
    }


};