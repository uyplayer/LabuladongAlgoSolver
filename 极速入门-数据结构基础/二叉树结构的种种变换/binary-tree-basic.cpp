//
// Created by uyplayer on 2024-09-02.
//

template<typename T>
class TreeNode {
public:
    T value;
    TreeNode * Left;
    TreeNode * Right;
    explicit TreeNode(T val):value(val),Left(nullptr),Right(nullptr){};
};



void make_example(){
    auto* root = new TreeNode<int>(1);
    root->Left = new TreeNode<int>(2);
    root->Right = new TreeNode<int>(3);
    root->Left->Left = new TreeNode<int>(4);
    root->Right->Left = new TreeNode<int>(5);
    root->Right->Right = new TreeNode<int>(6);
}
