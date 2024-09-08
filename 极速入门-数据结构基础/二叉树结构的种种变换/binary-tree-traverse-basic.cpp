//
// Created by uyplayer on 4/9/2024.
//


#include <vector>
#include <queue>
#include <iostream>


class TreeNode
{
public:
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val): value(val), left(nullptr), right(nullptr)
    {
    };
};


void traverse(TreeNode* root, std::vector<int>& preorderResult, std::vector<int>& inorderResult,
              std::vector<int>& postorderResult)
{
    if (root == nullptr)
    {
        return;
    }
    // 前
    preorderResult.push_back(root->value);
    // 递归遍历左子树
    traverse(root->left, preorderResult, inorderResult, postorderResult);
    // 中
    preorderResult.push_back(root->value);
    // 后序遍历
    traverse(root->right, preorderResult, inorderResult, postorderResult);
    // 后
    preorderResult.push_back(root->value);
}


void levelOrderTraverse1(TreeNode* root)
{
    if (root == nullptr)
    {
        return;
    }
    // 这种遍历我们不知道层次的那个层
    std::queue<TreeNode*> q;
    q.push(root);
    while (q.size() != 0)
    {
        // 出队
        TreeNode* cur = q.front();
        q.pop();
        // 可以看到层序遍历是一层一层，从左到右的遍历二叉树节点
        std::cout << cur->value << std::endl;
        // 左孩子的进队
        if (cur->left != nullptr)
        {
            q.push(cur->left);
        }
        // 右孩子进队
        if (cur->right != nullptr)
        {
            q.push(cur->right);
        }
    }
}

void levelOrderTraverse2(TreeNode* root)
{
    if (root == nullptr)
    {
        return;
    }
    int depth = 1;
    std::queue<TreeNode*> q;
    q.push(root);
    while (q.size() != 0)
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode* cur = q.front();
            q.pop();
            std::cout << cur->value << std::endl;
            if (cur->left != nullptr)
            {
                q.push(cur->left);
            }
            if (cur->right != nullptr)
            {
                q.push(cur->right);
            }
        }
        depth++;
    }
}


void levelOrderTraverse3(TreeNode* root)
{
    if (root == nullptr)
    {
        return;
    }
    int depth = 1;
    std::queue<TreeNode*> q;
    q.push(root);
    while (q.size() != 0)
    {
        int size = q.size();
        while (size-- > 0)
        {
            TreeNode* cur = q.front();
            q.pop();
            std::cout << cur->value << std::endl;
            if (cur->left != nullptr)
            {
                q.push(cur->left);
            }
            if (cur->right != nullptr)
            {
                q.push(cur->right);
            }
        }
        depth++;
    }
}


class State
{
public:
    TreeNode* node;
    int depth;

    State(TreeNode* node, int depth) : node(node), depth(depth)
    {
    };
};


void levelOrderTraverse4(TreeNode* root)
{
    if (root == nullptr)
    {
        return;
    }
    std::queue<State> q;
    q.push(State{root, 1});
    while (q.size() != 0)
    {
        State cur = q.front();
        q.pop();
        // 访问 cur 节点，同时知道它的路径权重和
        std::cout << "depth = " << cur.depth << ", val = " << cur.node->value << std::endl;
        // 把 cur 的左右子节点加入队列
        if (cur.node->left != nullptr)
        {
            q.push(State{cur.node->left, cur.depth + 1});
        }
        if (cur.node->right != nullptr)
        {
            q.push(State(cur.node->right, cur.depth + 1));
        }
    }
}
