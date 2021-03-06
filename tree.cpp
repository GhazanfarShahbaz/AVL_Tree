#include "tree.h"

template<class T>
Tree<T>::Tree():root_(nullptr){}

template<class T>
Tree<T>::Tree(TreeNode<T>* root): root_(root){}

template<class T>
Tree<T>::~Tree(){

}

template<class T>
void Tree<T>::insert(TreeNode<T>* node){
    if(root_ == nullptr){
        root_ = node;
        return;
    }

    TreeNode<T>* parse = root_;
    bool insert = false;

    while(not insert){
        if(parse->getValue() < node->getValue()){
            if(parse->getRight()){
                parse = parse->getRight();
            }
            else{
                parse->setRight(node);
                insert = true;
            }
        }
        else if(parse->getValue() > node->getValue()){
            if(parse->getLeft()){
                parse = parse->getLeft();
            }
            else{
                parse->setLeft(node);
                insert = true;
            }
        }
        else{
            return;
        }
    }

    int balance = subtreeHeightDifference(root_->getLeft(), root_->getRight());  

    if (balance > 1 && node->getValue() < root_->getLeft()->getValue()){
        root_  = rotateRight(getBrokenNode(node->getValue(), root_));  
    } 
    else if (balance < -1 &&  node->getValue() > root_->getRight()->getValue()){
        root_ = rotateLeft(getBrokenNode(node->getValue(), root_));  
    }
    else if (balance > 1 && node->getValue() > root_->getLeft()->getValue()){   
        TreeNode<T>* ph = getBrokenNode(node->getValue(), root_);
        root_->setLeft(rotateLeft(ph->getLeft()));  
        root_ = rotateRight(ph);  
    } 
    else if (balance < -1 and node->getValue() > root_->getRight()->getValue()){  
        TreeNode<T>* ph = getBrokenNode(node->getValue(), root_);
        root_->setRight(rotateRight(ph->getRight()));  
        root_ = rotateLeft(ph);  
    }
  
    return;
}

template<class T>
int Tree<T>::depth() const{
    return getDepth(root_, 0);
}

template<class T>
bool Tree<T>::search(const T val) const{
    return searchProperty(root_, val);
}

template<class T>
TreeNode<T>* Tree<T>::getRoot() const{
    return root_;
}

template<class T>
bool Tree<T>::isFullBinaryTree() const{
    return checkIfFull(root_);
}

template<class T>
T Tree<T>::getGreatestValue() const{
    TreeNode<T>* parse = root_;
    while(parse->getRight()){
        parse = parse->getRight();
    }
    return parse->getValue();
}

template<class T>
T Tree<T>::getSmallestValue() const{
    TreeNode<T>* parse = root_;
    while(parse->getLeft()){
        parse = parse->getLeft();
    }
    return parse->getValue();
}

template<class T>
int Tree<T>::numberOfNodes() const{
    return getNumberOfNodes(root_);
}


template<class T>
void Tree<T>::pathToNode(const T target) const{
    std::string path = "";
    TreeNode<T>* parser = root_;
    while(parser){
        if(parser->getValue() >  target and parser->getLeft()){
            path += std::to_string(parser->getValue()) + " Went Left "; 
            parser = parser->getLeft();
        }
        else if(parser->getValue() < target and parser->getRight()){
            path += std::to_string(parser->getValue()) + " Went Right "; 
            parser = parser->getRight();
        }
        else if(parser->getValue() == target){
            path += std::to_string(target);
            break;
        }
        else{
            std::cout << "Not Found" << std::endl;
            return;
        }
    }
    std::cout << path << std::endl;
}

template<class T>
void Tree<T>::postOrderTraversal() const{
    printInOrder(root_);
}

template<class T>
void Tree<T>::preOrderTraversal() const{
    printPreOrder(root_);
}

template<class T>
void Tree<T>::inOrderTraversal() const{
    printInOrder(root_);
}

template<class T>
void Tree<T>::printPostOrder(TreeNode<T>* node) const{
    if(node){
        printPostOrder(node->getLeft());
        printPostOrder(node->getRight());
        std::cout << node->getValue() << std::endl;
    }
}

template<class T>
void Tree<T>::printPreOrder(TreeNode<T>* node) const{
    if(node){
        std::cout<< node->getValue() << std::endl;
        printPostOrder(node->getLeft());
        printPostOrder(node->getRight());
    }
}

template<class T>
void Tree<T>::printInOrder(TreeNode<T>* node) const{
    if(node){
        printInOrder(node->getLeft());
        std::cout << node->getValue() << std::endl;
        printInOrder(node->getRight());
    }
}

template<class T>
void Tree<T>::clear(TreeNode<T>* node){
    if(node){
        clear(node->getLeft());
        clear(node->getRight());
        delete node;
    }
}


template<class T>
bool Tree<T>::searchProperty(TreeNode<T>*node, T target) const{
    if(node){
        if(node->getValue() == target){
            return true;
        }
        if(node->getValue() > target){
            return searchProperty(node->getLeft(), target);
        }
        else if(node->getValue() < target){
            return searchProperty(node->getRight(), target);
        }
        // return searchProperty(node->getLeft(), target) or searchProperty(node->getRight(), target);
    }
    return false;
}

template<class T>
int Tree<T>::getDepth(TreeNode<T>*node, int curr) const{
    if(node){
        curr++;
        return std::max(getDepth(node->getRight(), curr), getDepth(node->getLeft(), curr));
    }
    return curr;
}

template<class T>
bool Tree<T>::checkIfFull(const TreeNode<T>*node) const{
    if(node){
        if((node->getRight() and not node->getLeft()) or (node->getLeft() and not node->getRight())){
            return false;
        }
        return true and checkIfFull(node->getRight()) and checkIfFull(node->getLeft());
    }
    return true;
}

template<class T>  
int Tree<T>::subtreeHeightDifference(TreeNode<T>* left, TreeNode<T>* right) const{
    return getDepth(left,0) - getDepth(right,0);
}

template<class T>
bool Tree<T>::checkIfBST() const{
    return check(root_);
}
 

template<class T>
TreeNode<T>* Tree<T>::rotateRight(TreeNode<T>* node){
    TreeNode<T>* next = node->getLeft();
    TreeNode<T>* after_next = next->getRight();

    next->setRight(node);
    node->setLeft(after_next);

    return next;
}

template<class T>
TreeNode<T>* Tree<T>::rotateLeft(TreeNode<T>* node){
    TreeNode<T>* next = node->getRight();
    TreeNode<T>* after_next = next->getLeft();

    next->setLeft(node);
    node->setRight(after_next);

    return next;
}

template<class T>
TreeNode<T>* Tree<T>::getBrokenNode(T value, TreeNode<T>* root){
    if(root){
        if(abs(subtreeHeightDifference(root->getLeft(), root->getRight())) > 1){
            return root;
        }
        else{
            if(root->getValue() < value){
                return getBrokenNode(value, root->getRight());
            }
            else if(root->getValue() > value){
                return getBrokenNode(value, root->getLeft());
            }
        }
    }
    return nullptr;
}

template<class T>
int Tree<T>::getNumberOfNodes(TreeNode<T>* node) const{
    if(node){
        return 1 + getNumberOfNodes(node->getLeft()) + getNumberOfNodes(node->getRight());
    }
    return 0;
}

template<class T>
bool Tree<T>::check(TreeNode<T>* node) const{
    if(node){
        std::cout << abs(subtreeHeightDifference(node->getLeft(), node->getRight())) << std::endl;
        if(abs(subtreeHeightDifference(node->getLeft(), node->getRight())) > 1){
            return false;
        }
        else{
            return true and check(node->getLeft()) and check(node->getRight());
        }
    }
    return true;
}