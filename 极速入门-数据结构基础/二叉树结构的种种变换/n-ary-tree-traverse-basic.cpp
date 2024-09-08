//
// Created by uyplayer on 8/9/2024.
// 多叉树的递归-层序遍历
//


#include <iostream>
#include <vector>

class TreeNode
{
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    explicit TreeNode(int v) : data(v), left(nullptr), right(nullptr){};
};

class Node
{
public:
    int data;
    std::vector<TreeNode*> children;
};

// 二叉树的遍历框架
void traverse(TreeNode* root) {
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
void traverse_n_array(TreeNode* root)
{
    if (root == nullptr) {
        return;
    }
    for(auto child : root->data)
    {
        traverse(child);
    }
}