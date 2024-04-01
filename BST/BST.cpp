#include "BST.h"

template<typename T>
BST<T>::BST() : root(nullptr) {}

template<typename T>
BST<T>::~BST() {
    destroyTree(root);
}

template<typename T>
void BST<T>::insert(const T& val) {
    insert(root, val);
}

template<typename T>
void BST<T>::insert(TreeNode<T>*& node, const T& val) {
    if (node == nullptr) {
        node = new TreeNode<T>(val);
    } else if (val < node->data) {
        insert(node->left, val);
    } else {
        insert(node->right, val);
    }
}

template<typename T>
void BST<T>::remove(const T& val) {
    root = remove(root, val);
}

template<typename T>
TreeNode<T>* BST<T>::remove(TreeNode<T>* node, const T& val) {
    if (node == nullptr) {
        return nullptr;
    }

    if (val < node->data) {
        node->left = remove(node->left, val);
    } else if (val > node->data) {
        node->right = remove(node->right, val);
    } else {
        if (node->left == nullptr) {
            TreeNode<T>* temp = node->right;
            delete node;
            return temp;
        } else if (node->right == nullptr) {
            TreeNode<T>* temp = node->left;
            delete node;
            return temp;
        }

        TreeNode<T>* minRight = findMin(node->right);
        node->data = minRight->data;
        node->right = remove(node->right, minRight->data);
    }
    return node;
}

template<typename T>
bool BST<T>::search(const T& val) const {
    TreeNode<T>* current = root;
    while (current != nullptr) {
        if (val == current->data) {
            return true;
        } else if (val < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return false;
}

template<typename T>
TreeNode<T>* BST<T>::findMin(TreeNode<T>* node) const {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

template<typename T>
void BST<T>::destroyTree(TreeNode<T>* node) {
    if (node != nullptr) {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}