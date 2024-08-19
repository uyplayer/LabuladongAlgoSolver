//
// Created by uyplayer on 2024-08-19.
//

#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

template<typename Tk,typename Tv>
class ChainingHashMap{

private:
    struct KVNode {
            Tk key;
            Tv value;
            KVNode(Tk key,Tv value):key(key),value(value){};
    };

    std::vector<std::list<KVNode>> buckets;
    size_t bucket_count;



};