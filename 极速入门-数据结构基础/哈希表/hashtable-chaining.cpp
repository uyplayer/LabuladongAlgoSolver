//
// Created by uyplayer on 2024-08-19.
//

#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <optional>

template<typename Tk, typename Tv>
class ChainingHashMap {

private:
    struct KVNode {
        Tk key;
        Tv value;

        KVNode(Tk key, Tv value) : key(key), value(value) {};
    };

    std::vector<std::list<KVNode>> buckets;
    size_t bucket_count;


    size_t HashFuck(const Tk &key) {
        std::hash<Tk> hasher;
        return hasher(key) % bucket_count;
    }


public:
    explicit ChainingHashMap(size_t bucket_count = 10) : bucket_count(bucket_count) {
        buckets.resize(bucket_count);
    }

    void insert(const Tk &key, const Tv &value) {

        size_t index = HashFuck(key);
        // key 存在
        for (auto &node: buckets[index]) {
            if (node.key == key) {
                node.value = value;
                return;
            }
        }
        // key 不存在
        buckets[index].emplace_back(key, value);
    }

    std::optional<Tv> find(const Tk &key) {
        size_t index = HashFuck(key);
        for (auto &node: buckets[index]) {
            if (node.key == key) {
                return &node.value;
            }
        }
        return std::nullopt;
    }
    // 删除操作
    bool erase(const Tk &key) {

        size_t index = HashFuck(key);
        // 先找key 对应的桶
        auto &bucket = buckets[index];
        // 遍历对应的node 和 key
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->key == key) {
                bucket.erase(it);
                return true;
            }
        }
        return false;
    }



};