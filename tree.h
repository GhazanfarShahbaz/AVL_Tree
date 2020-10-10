#ifndef TREE_H
#define TREE_H

#include "treeNode.h"

template<class T> class Tree{
    public:

        //Construcor
        Tree();

        /** Paramterized Constructor
         * @param root: the root which will be set to the tree
        **/ 
        Tree(TreeNode<T>* root);

        //Destructor
        ~Tree();
        
        // Mutator Functions

        /** Insert Function
         * Inserts node into the tree while maintaining the search property of the tree
         * @param node: the node you want to insert
        **/ 
        void insert(TreeNode<T>* node);

        // Acessor Functions

        /** Get Root Function
         * Returns the root of the tree
         * @return Returns a TreeNode type T which is the root
        **/
        TreeNode<T>* getRoot() const;
        
        /** Depth Function
         * Obtains the depth of the function
         * @return returns an integer the with the depth of the tree
        **/ 
        int depth() const;

        /** Search Function
         * Checks if a value is in the tree
         * @param val: a T type which will be searched for in the tree
         * @return: returns true if found and false if not
        **/ 
        bool search(const T val) const;

        /** Full Binary Tree
         * Checks to see if the binary tree is a full binary tree
         * @return: returns true if all nodes havw either 2 children or node except for leaves which will always have none returns false if a node has 1 leaf
        **/
        bool isFullBinaryTree() const;

        /** Greatest Value Function
         * Finds the largest value in the tree
         * @return: returns a type T value with the greatest valuethat exists in the tree
        **/
        T getGreatestValue() const;

        /** Smallest Value Functions
         * Finds the smallest value in the tree
         * @return: returns a type T value with the smallest value in the tree
        **/ 
        T getSmallestValue() const;

        /** Path To Node Functions
         * If a given value exists in the tree it will retun the path to it
         * @param target: a T value that will be searched for in the tree
         * @post: prints the path if found prints Not Found if value is not in the tree
        **/ 
        void pathToNode(const T target) const;

        /** Post Order Traveral Functions
         * Traverses the tree in post order
         * @post: prints elements in the tree in post order
        **/ 
        void postOrderTraversal() const;

        /** Pre Order Traveral Functions
         * Traverses the tree in pre order
         * @post: prints elements in the tree in pre order
        **/ 
        void preOrderTraversal() const;

        /** In Order Traveral Functions
         * Traverses the tree in order
         * @post: prints elements in the tree in order
        **/ 
        void inOrderTraversal() const;
 
    private:
        TreeNode<T>* root_; //Root of the tree

        /** Clear Function
         * Clears all values in the tree, accessed by the destructor
         * @param node: the node which the function will begin at, recursively this node will be traveled by post order traversal
        **/
        void clear(TreeNode<T>* node);

        /** Seatch Property Function
         * Searches for an element in the tree, accessed by the search function
         * @param node: the node that will be traversed
         * @param target: the value which will be looked for
         * @return: will return true of the value is found and false if the value is nto
        **/
        bool searchProperty(TreeNode<T>*node, T target) const;

        /** Post Order Function
         * Prints the tree in post order, accessed by the function postOrderTraversal(...)
         * @param node: the node which is being traveled 
         * @post prints the tree in post order
        **/
        void printPostOrder(TreeNode<T>* node) const;

        /** In Order Function
         * Prints the tree in post order, accessed by the function inOrderTraversal(...)
         * @param node: the node which is being traveled 
         * @post prints the tree in order
        **/
        void printInOrder(TreeNode<T>* node) const;

        /** Pre Order Function
         * Prints the tree in post order, accessed by the function preOrderTraversal(...)
         * @param node: the node which is being traveled 
         * @post prints the tree in pre order
        **/
        void printPreOrder(TreeNode<T>* node) const;

        /** Get Depth Function
         * Traverses the tree and gets its depth, accessed by the search function
         * @param node: the node being traversed
         * @param curr: current depth of the function
         * @return: returns an integer with the depth of the function
        **/ 
        int getDepth(TreeNode<T>* node, int curr = 0) const;

        /** Check If Full Function
         * Checks if the tree is a full binary tree, acessed by the function isFullBinary(...)
         * @param node: the node being traversed
         * @return: returns true if all nodes havw either 2 children or node except for leaves which will always have none returns false if a node has 1 leaf
        **/ 
        bool checkIfFull(const TreeNode<T>* node) const;

        // AVL Functions
        /** Subtree Height Difference Function
         * Gets the difference between the height of 2 subtrees, accessed by the insert function 
         * @param left: the left subtree node to be compared
         * @param right: the right subtree node to be compared
         * @return: an integer with the height difference between the 2 subtrees
        **/ 
        int subtreeHeightDifference(TreeNode<T>* left, TreeNode<T>* right);

        /** Rotate Right Function
         * Rotates the tree right, in order to preserve search property this is accessed by the insert function
         * @param node: the node to be rotated
         * @return: a TreeNode that will be set to another to effectively rotate the tree
        **/
        TreeNode<T>* rotateRight(TreeNode<T>* node);

        /** Rotate Left Function
         * Rotates the tree left, in order to preserve search property this is accessed by the insert function
         * @param node: the node to be rotated
         * @return: a TreeNode that will be set to another to effectively rotate the tree
        **/
        TreeNode<T>* rotateLeft(TreeNode<T>* node);

        /**
         *  Get Broken Node Function
         * Gets the node whose balance has been messed up by insertion
         * @param value: the value that was inserted
         * @param root: the root node
         * @return: a TreeNode whose value was broken, if nothing was broken then a nullptr will be returned
        
        **/
        TreeNode<T>* getBrokenNode(T value, TreeNode<T>* root);

};




#include "tree.cpp"
#endif