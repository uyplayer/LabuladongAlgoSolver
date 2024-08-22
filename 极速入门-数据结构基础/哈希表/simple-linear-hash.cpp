//
// Created by uyplayer on 2024-08-22.
//



class SimpleLinearProbingHashMap {
private:
    struct KVNode {
        int key;
        int value;

        KVNode(int k, int v) : key(k), value(v) {};
    };

    KVNode *table[10] = {nullptr};

    int hash(int key) {
        return key % 10;
    }

public:
    void put(int key, int value){
         int index = hash(key);
         KVNode* node = table[index];
         if (node == nullptr) {
            table[index] = new KVNode(key, value);
        }else {
             while (index < 10 && table[index] != nullptr && table[index]->key != key) {
                 index++;
             }
             table[index] = new KVNode(key, value);
         }
    }
    int get(int key) {
        int index = hash(key);
        while (index < 10 && table[index] != nullptr && table[index]->key != key) {
            index++;
        }
        if (index >= 10 || table[index] == nullptr) {
            return -1;
        }
        return table[index]->value;
    }


};