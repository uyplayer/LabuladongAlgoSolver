//
// Created by uyplayer on 2024-08-10.
//


#include <iostream>


int main() {
    std::cout << "动态数组代码实现" << std::endl;
    return 0;
}


template<typename T>
class DynamicArray {

public:
    DynamicArray():size(0),capacity(10) {
        data = new T[capacity];
    }
    ~DynamicArray() {
        delete []data;
    }

private:
    T* data;
    size_t size;
    size_t capacity;
};