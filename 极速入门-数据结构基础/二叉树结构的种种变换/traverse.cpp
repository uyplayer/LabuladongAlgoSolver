//
// Created by uyplayer on 4/9/2024.
//



class TreeNode {
public:
    int value;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val):value(val),left(nullptr),right(nullptr){};
};



void traverse(TreeNode * root){
    if (root == nullptr){
        return;
    }
    traverse(root->left);
    traverse(root->right);
 }
