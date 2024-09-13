//
// Created by uyplayer on 8/9/2024.
// 多叉树的递归-层序遍历
//


#include <iostream>
#include <vector>
#include <queue>

class TreeNode {
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int v) : data(v), left(nullptr), right(nullptr) {};
};

class Node {
public:
    int data;
    std::vector<Node *> children;
};

// 二叉树的遍历框架
void traverse(TreeNode *root) {
    if (root == nullptr) {
        return;
    }
    // 前序位置
    traverse(root->left);
    // 中序位置
    traverse(root->right);
    // 后序位置
}

// N 叉树的遍历框架
void traverse_n_array(TreeNode *root) {
    if (root == nullptr) {
        return;
    }
    for (auto child: root->data) {
        traverse(child);
    }
}


void levelOrderTraverse(Node *root) {
    if (root == nullptr) {
        return;
    }
    std::queue<Node *> q;
    q.push(root);
    while (!q.empty()) {
        auto node = q.front();
        q.pop();
        for (auto child: node->children) {
            q.push(child);
        }
    }
}


void levelOrderTraverse2(Node *root) {
    if (root == nullptr) {
        return;
    }

    int depth = 1;
    std::queue<Node *> q;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();

        for (int i = 0; i < size; ++i) {
            auto node = q.front();
            q.pop();
            for (auto child: node->children) {
                q.push(child);
            }
        }
        depth++;

    }

}


class State {
public:
    Node *node;
    int depth;

    State(Node *node, int depth) : node(node), depth(depth) {}
};

void levelOrderTraverse3(Node *root) {
    if (root == nullptr) {
        return;
    }

    std::queue<State> q;
    q.push(State(root, 1));
    while (!q.empty()) {
        auto state = q.front();
        q.pop();
        Node *cur = state.node;
        int depth = state.depth;
        for (Node *child: cur->children) {
            q.push(State(child, depth + 1));
        }
    }

}
