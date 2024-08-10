#include <iostream>

template<typename T>
class DynamicArray {
public:
    DynamicArray() : size(0), capacity(10) {
        data = new T[capacity];
    }

    ~DynamicArray() {
        delete[] data;
    }

    void add_value(T value) {
        if (size == capacity) {
            expand_capacity();
        }
        data[size] = value;
        ++size;
    }

    void pop() {
        if (size == 0) {
            std::cerr << "数组是空的，不能pop操作" << std::endl;
            return;
        }
        --size;
    }

    void print_values() const {
        for (size_t i = 0; i < size; ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }

private:
    void expand_capacity() {
        auto new_capacity = static_cast<size_t>(capacity * expand_factor);
        T* new_data = new T[new_capacity];
        for (size_t i = 0; i < size; ++i) {
            new_data[i] = data[i];
        }
        // 删除old data 指向的内存
        delete[] data;
        // 更新data指向的内存
        data = new_data;
        capacity = new_capacity;
    }

private:
    T* data;
    size_t size;
    size_t capacity;
    float expand_factor{2.5};
};

int main() {
    std::cout << "动态数组代码实现" << std::endl;
    DynamicArray<int> arr;
    arr.add_value(1);
    arr.add_value(2);
    arr.add_value(3);
    arr.add_value(4);

    std::cout << "动态数组内容: ";
    arr.print_values();

    arr.pop();
    std::cout << "移除最后一个元素后的数组内容: ";
    arr.print_values();

    arr.pop();
    arr.pop();
    arr.pop();

    std::cout << "移除所有元素后的数组内容: ";
    arr.print_values();

    return 0;
}
