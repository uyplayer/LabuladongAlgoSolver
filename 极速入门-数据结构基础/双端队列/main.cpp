//
// Created by uyplayer on 2024-08-14.
//


#include <iostream>
#include <deque>

int main(){


    std::cout << "双端队列（Deque）" << std::endl;

     std::deque<int> dq;
    dq.push_front(10);
    dq.push_front(20);
    dq.push_back(30);
    dq.push_back(40);

    std::cout << "Deque contents: ";
    for(int num : dq) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    dq.pop_front();
    dq.pop_back();

    std::cout << "Deque after popping: ";
    for(int num : dq) {
        std::cout << num << " ";
    }
    std::cout << std::endl;


    return 0;


}