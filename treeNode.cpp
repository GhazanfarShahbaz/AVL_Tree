#include "treeNode.h"

template<class T>
TreeNode<T>::TreeNode(): value_(0), left_(nullptr), right_(nullptr){}

template<class T>
TreeNode<T>::TreeNode(const T& data, TreeNode<T>* left, TreeNode<T>* right): value_(data), left_(left), right_(right){}

template<class T>
TreeNode<T>::~TreeNode(){
    left_ = nullptr;
    delete(left_);
    right_ = nullptr;
    delete(right_);
}

template<class T>
void TreeNode<T>::setValue(const T& data){ 
    value_ = data;
}

template<class T>
void TreeNode<T>::setLeft(TreeNode<T>* left){
    left_ = left;
}

template<class T>
void TreeNode<T>::setRight(TreeNode<T>* right){ 
    right_ = right;
}

template<class T>
T TreeNode<T>::getValue() const{
    return value_;
}

template<class T>
TreeNode<T>* TreeNode<T>::getLeft() const{
    return left_;
}

template<class T>
TreeNode<T>* TreeNode<T>::getRight() const{
    return right_;
}