//
// Created by uyplayer on 2024-08-26.
//

#include <vector>
#include <list>
#include <algorithm>

class HashSet {

public:
    HashSet(size_t size = 10) : table(size) {}

    bool insert(int value) {
        size_t index = hash(value) % table.size();
        auto &chain = table[index];
        for (int item: chain) {
            if (item == value) return false;
        }
        chain.push_back(value);
        return true;
    }

    bool contains(int value) const {
        size_t index = hash(value) % table.size();
        const auto &chain = table[index];
        for (int item: chain) {
            if (item == value) return true;
        }
        return false;
    }

    bool remove(int value) {
        size_t index = hash(value) % table.size();
        auto &chain = table[index];
        for (auto it = chain.begin(); it != chain.end(); ++it) {
            if (*it == value) {
                chain.erase(it);
                return true;
            }
        }
        return false;
    }

private:

    std::vector<std::list<int>> table;
    std::hash<int> hash;
};