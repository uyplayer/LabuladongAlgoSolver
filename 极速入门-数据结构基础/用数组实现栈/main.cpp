#include <iostream>
#include <vector>

// 栈操作
void push(std::vector<int>& stack, int value) {
    stack.push_back(value);
}

void pop(std::vector<int>& stack) {
    if (!stack.empty()) {
        stack.pop_back();
    }
}

int top(const std::vector<int>& stack) {
    if (!stack.empty()) {
        return stack.back();
    }
    return -1;
}

// 队列操作
void enqueue(std::vector<int>& queue, int value) {
    queue.push_back(value);
}

void dequeue(std::vector<int>& queue) {
    if (!queue.empty()) {
        queue.erase(queue.begin());
    }
}

int front(const std::vector<int>& queue) {
    if (!queue.empty()) {
        return queue.front();
    }
    return -1;
}

int main() {
    std::cout << "用数组实现栈和队列" << std::endl;

    // 栈操作
    std::vector<int> stack;
    push(stack, 10);
    push(stack, 52);
    std::cout << "栈顶元素: " << top(stack) << std::endl;
    pop(stack);
    std::cout << "栈顶元素: " << top(stack) << std::endl;

    // 队列操作
    std::vector<int> queue;
    enqueue(queue, 10010);
    enqueue(queue, 100);
    enqueue(queue, 5255);
    std::cout << "队列头元素: " << front(queue) << std::endl;
    dequeue(queue);  // 移除队首元素
    std::cout << "队列头元素: " << front(queue) << std::endl;

    return 0;
}
