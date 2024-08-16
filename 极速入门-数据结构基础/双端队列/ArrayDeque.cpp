//
// Created by uyplayer on 2024-08-14.
//



#include <iostream>
#include <vector>


template<typename T>
class ArrayDe {
    ArrayDe() = default;
    explicit ArrayDe(size_t size):data(size){};
    // 拷贝构造函数
    ArrayDe(const ArrayDe& other):data(other.data){};
    ArrayDe(ArrayDe&& other) noexcept : data(std::move(other.data)){};
    ArrayDe& operator=(ArrayDe&& other) noexcept {
        if (this != &other) {
             data = std::move(other.data);
        }
         return *this;
    }

     ~ArrayDe() = default;

    void push_back(const T& value) {
        data.push_back(value);
    }

    T& operator[](size_t index) {
        return data[index];
    }

    const T& operator[](size_t index) const {
        return data[index];
    }


    size_t size() const {
        return data.size();
    }

    void print() const {
        for (const auto& item : data) {
            std::cout << item << " ";
        }
        std::cout << std::endl;
    }
private:
    std::vector<T> data;
};

