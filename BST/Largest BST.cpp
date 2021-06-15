/*
Largest BST

Given a Binary tree, find the largest BST subtree. That is, you need to find the BST with maximum height in the given binary tree.
Return the height of largest BST.
Input format :

Line 1 : Elements in level order form (separated by space)

(If any node does not have left or right child, take -1 in its place)

Sample Input 1:
5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output 1:
2
*/

// Following is the Binary Tree node structure
/**************
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};
***************/
#include<bits/stdc++.h>
using namespace std;
#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
    ~BinaryTreeNode() {
    	if(left) 
       		delete left;
    	if(right) 
       		delete right;
    }
};

using namespace std;
#include "solution.h"

BinaryTreeNode<int>* takeInput() {
    int rootData;
    //cout << "Enter root data : ";
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
	q.pop();
        int leftChild, rightChild;
        //cout << "Enter left child of " << currentNode -> data << " : ";
        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
        //cout << "Enter right child of " << currentNode -> data << " : ";
        cin >> rightChild;
        if(rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }
    return root;
}


class Values{
    public:
    int min, max, height;
    bool status;
    Values(int min, int max, bool status, int height){
        this->min = min;
        this->max = max;
        this->status = status;
        this->height = height;
    }
};

Values helper(BinaryTreeNode<int>* root){
    if(root == NULL){
        Values V(INT_MAX, INT_MIN, true, 0);
        return V;
    }
    Values left = helper(root->left);
    Values right = helper(root->right);
    int minval = min(root->data, min(left.min, right.min));
    int maxval = max(root->data, max(left.max, right.max));
    if(left.status && right.status)
        if(left.max<root->data && right.min>root->data){
            Values V(minval, maxval, true, 1+max(right.height, left.height));
            return V;
        }
    Values V(minval, maxval, false, max(right.height, left.height));
    return V;
}

int largestBSTSubtree(BinaryTreeNode<int> *root) {
    Values V = helper(root);
    return V.height;
}





int main() {
    BinaryTreeNode<int>* root = takeInput();
    cout << largestBSTSubtree(root);
    delete root;
}

