/*
Code: BST Class

Implement the BST class which includes following functions -
1. search
Given an element, find if that is present in BSt or not. Return true or false.
2. insert -
Given an element, insert that element in the BST at the correct position. Assume unique elements will be given.
3. delete -
Given an element, remove that element from the BST. If the element which is to be deleted has both children, replace that with the minimum element from right sub-tree.
4. printTree (recursive) -
Print the BST in ithe following format -
For printing a node with data N, you need to follow the exact format -
N:L:x,R:y
wherer, N is data of any node present in the binary tree. x and y are the values of left and right child of node N. Print the children only if it is not null.
There is no space in between.
You need to print all nodes in the recursive format in different lines.
Note : main function is given for your reference which we are using internally to test the class.
*/

#include<iostream>
using namespace std;

template <typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;
    
    BinaryTreeNode(T data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

#include "BinarySearchTree.h"


//code

#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;

class BST {
    
	BinaryTreeNode<int> *root;
    
    void print(BinaryTreeNode<int> *node) {
        if(node==NULL)
            return;
        cout<<node->data<<":";
        if(node->left!=NULL)
            cout<<"L:"<<node->left->data<<",";
        if(node->right!=NULL)
            cout<<"R:"<<node->right->data;
        cout<<endl;
        print(node->left);
        print(node->right);
    }
    
    BinaryTreeNode<int>* add(int data, BinaryTreeNode<int>* node) {
        if(node==NULL) {
            BinaryTreeNode<int> *newNode = new BinaryTreeNode<int>(data);
            return newNode;
        }
        if(node->data<data)
            node->right = add(data,node->right);
        else
            node->left = add(data,node->left);
        return node;
    }
    
    bool search(BinaryTreeNode<int> *node, int data) {
        if(node==NULL)
            return false;
        if(node->data==data)
            return true;
        return search(node->left,data) || search(node->right,data);
    }
    
    int minimum(BinaryTreeNode<int>* node) {
        if(node==NULL)
            return INT_MAX;
        return min(node->data,min(minimum(node->right),minimum(node->left)));
    }
    
    BinaryTreeNode<int>* del(BinaryTreeNode<int>* node, int data) {
        if(node==NULL)
            return NULL;
        if(node->data>data) {
            node->left = del(node->left,data);
            return node;
        }
        if(node->data<data) {
            node->right = del(node->right,data);
            return node;
        }
        if(node->left==NULL && node->right==NULL)
            return NULL;
        if(node->left==NULL)
            return node->right;
        if(node->right==NULL)
            return node->left;
        int replace = minimum(node->right);
        node->data=replace;
        node->right = del(node->right,replace);
        return node;
    }
    
    public:
    
     void insert(int data) {
        root = add(data,root);
     }
    
    void printTree() {
        print(root);
    }
    
    void deleteData(int data){
        root = del(root,data);
    }
    
    bool hasData(int data) {
        return search(root,data);
    }
    
};



int main(){
    BST *tree = new BST();
    int choice, input;
    while(true){
        cin>>choice;
        switch(choice){
            case 1:
                cin >> input;
                tree->insert(input);
                break;
            case 2:
                cin >> input;
                tree->deleteData(input);
                break;
            case 3:
                cin >> input;
                if(tree->hasData(input)) {
                    cout << "true" << endl;
                }
                else {
                    cout << "false" << endl;
                }
                break;
            default:
                tree->printTree();
                return 0;
                break;
        }
    }
}
