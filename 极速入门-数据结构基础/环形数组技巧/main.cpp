#include <iostream>
#include <stdexcept>

template<typename T>
class CycleArray {
public:
    explicit CycleArray(size_t capacity): start(0), end(0), size(0), capacity(capacity) {
        data = new T[capacity];
    }

    ~CycleArray() {
        delete []data;
    }

    void add_value(T value) {
        if (size == capacity) {
            start = (start + 1) % capacity;
        }
        data[end] = value;
        end = (end + 1) % capacity;
        if (size < capacity) {
            ++size;
        }
    }

    T get_value(size_t index) const {
        if (index >= size) {
            throw std::out_of_range("index 超过 索引");
        }
        return data[(start + index) % capacity];
    }




    bool is_empty() const {
        return size == 0;
    }

    bool is_full() const {
        return size == capacity;
    }

    size_t get_size() const {
        return size;
    }

private:
    T *data;
    size_t start;
    size_t end;
    size_t size;
    size_t capacity;
};

int main() {
    CycleArray<int> arr(100);

    arr.add_value(1);
    arr.add_value(2);
    arr.add_value(3);
    arr.add_value(4);
    arr.add_value(5);

    for (size_t i = 0; i < arr.get_size(); ++i) {
        std::cout << arr.get_value(i) << " ";
    }
    std::cout << std::endl;

    arr.add_value(6);

    std::cout << "添加 6: " << std::endl;
    for (size_t i = 0; i < arr.get_size(); ++i) {
        std::cout << arr.get_value(i) << " ";
    }
    std::cout << std::endl;

    return 0;
}
