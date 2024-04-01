#ifndef BST_H
#define BST_H

template<typename T>
struct TreeNode {
    T data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(const T& val) : data(val), left(nullptr), right(nullptr) {}
};

template<typename T>
class BST {
private:
    TreeNode<T>* root;

    void insert(TreeNode<T>*& node, const T& val);
    TreeNode<T>* remove(TreeNode<T>* node, const T& val);
    TreeNode<T>* findMin(TreeNode<T>* node) const;
    void destroyTree(TreeNode<T>* node);

public:
    BST();
    ~BST();

    void insert(const T& val);
    void remove(const T& val);
    bool search(const T& val) const;
};

#include "BST.cpp" // Include the implementation file because it's a template class

#endif // BST_H