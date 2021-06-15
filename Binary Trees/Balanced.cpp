/*
Balanced

Given a binary tree, check if its balanced i.e. depth of left and right subtrees of every node differ by at max 1. Return true if given binary tree is balanced, false otherwise.
Input format :

Elements in level order form (separated by space). If any node does not have left or right child, take -1 in its place.

Sample Input 1 :
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output 1 :
false
Sample Input 2 :
1 2 3 -1 -1 -1 -1
Sample Output 2 :
true
*/

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
//code

#include<cmath>
#include<algorithm>

class Pair {
    public:
    bool b;
    int Height;
};

Pair Balanced(BinaryTreeNode<int> *root) {
    if(root==NULL) {
        Pair P;
        P.b=true;
        P.Height=0;
        return P;
    }
    Pair P,P1,P2;
    P1=Balanced(root->left);
    P2=Balanced(root->right);
    P.Height=max(P1.Height,P2.Height)+1;
    if(P1.b == false || P2.b == false) {
        P.b=false;
        return P;
    }
    if(abs(P1.Height-P2.Height)<=1) {
        P.b=true;
        return P;
    }
    P.b=false;
    return P;
}

bool isBalanced(BinaryTreeNode<int> *root) {
    Pair P = Balanced(root);
    return P.b;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    if(isBalanced(root))
    	cout << "true" << endl;
    else
	cout << "false" << endl;
}
