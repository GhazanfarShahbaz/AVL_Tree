#ifndef TREE_H
#define TREE_H

#include "treeNode.h"

template<class T> class Tree{
    public:
        Tree();
        Tree(TreeNode<T>* root);
        TreeNode<T>* getRoot() const;
        int getHeight() const;
        void insert(TreeNode<T>* node);
        bool search(const T val) const;
        T getGreatestNode() const;
        T getSmallestNode() const;
        void pathToNode(const T target) const;
        void postOrderTraversal() const;
        void preOrderTraversal() const;
        void inOrderTraversal() const;
 
    private:
        TreeNode<T>* root_;

        bool searchProperty(TreeNode<T>*node, T target) const;
        void printPostOrder(TreeNode<T>* node) const;
        void printInOrder(TreeNode<T>* node) const;
        void printPreOrder(TreeNode<T>* node) const;
        int obtainHeight(TreeNode<T>* node, int curr = 0) const;
        // AVL Functions
        int subtreeHeightDifference(TreeNode<T>* left, TreeNode<T>* right);
        TreeNode<T>* rotateRight(TreeNode<T>* node);
        TreeNode<T>* rotateLeft(TreeNode<T>* node);

};




#include "tree.cpp"
#endif