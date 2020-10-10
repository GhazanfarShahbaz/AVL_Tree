#include <iostream>
#include <vector>
#include "tree.h"
#include "treeNode.h"
using namespace std;

int main(){
    TreeNode<int>* test= new TreeNode<int>(1);
    Tree<int> tree_test(test);
    std::vector<int> values{1};
    for(int i = 0; i < 10000; i++){
        values.push_back(rand()%1000000);
    }
    for(int value: values){
        // cout << value << " ";
        TreeNode<int>* curr = new TreeNode<int>(value);
        tree_test.insert(curr);
    }

    // TreeNode<int>* test= new TreeNode<int>(1);
    // // TreeNode<int>* test_two = new TreeNode<int>(2);
    // TreeNode<int>* test_three = new TreeNode<int>(3);
    // // test->setLeft(test_two);
    // test->setRight(test_three);
    // cout << " " << test->getValue()<< endl;
    // // cout << test->getLeft()->getValue() << " " << t est->getRight()->getValue() << endl;
    // Tree<int> tree_test(test);

    // TreeNode<int>* test_insert = new TreeNode<int>(4);
    // tree_test.insert(test_insert);
    // // tree_test.inOrderTraversal();
    // for(int x = 0; x  < 50; x++){
    //     TreeNode<int>* a = new TreeNode<int>;
    //     a->setValue(x);
    //     tree_test.insert(a);
    // }
    cout << endl;
    tree_test.pathToNode(values[70]);
    //  tree_test.inOrderTraversal();
    cout << tree_test.depth() << endl;
    cout << tree_test.getGreatestValue() << " " << tree_test.getSmallestValue() << endl;
    cout << *std::max_element(values.begin(), values.end()) << " " << *std::min_element(values.begin(), values.end()) << endl;
    tree_test.pathToNode(values[50]);
    // cout << tree_test.isFullBinaryTree();


    for(int value: values){
       if(not tree_test.search(value)){
           cout << "TEST FAILED" << endl;
           cout << value;
       }
    }

    // tree_test.clear(tree_test.getRoot());
    // cout << tree_test.getSmallestNode() << endl;;
//     TreeNode<int>* trav = tree_test.getRoot();
//     while(trav){
//         cout << trav->getValue() << endl;
//         trav = trav->getRight();
//     }
}