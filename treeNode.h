#ifndef TREE_NODE_H
#define TREE_NODE_H

template<class T> class TreeNode{
    public:
        TreeNode();
        TreeNode(const T& data, TreeNode<T>* left = nullptr, TreeNode<T>* right = nullptr);
        ~TreeNode();
        
        //Mutator Functions
        void setValue(const T& data);
        void setLeft(TreeNode<T>* left);
        void setRight(TreeNode<T>* right);

        //Acessor Functions
        T getValue() const;
        TreeNode<T>* getLeft() const;
        TreeNode<T>* getRight() const;

    private:
        T value_;
        TreeNode<T>* left_;
        TreeNode<T>* right_;
};

#include "treeNode.cpp"
#endif