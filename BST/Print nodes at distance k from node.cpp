/*
Print nodes at distance k from node

Given a binary tree, a node and an integer K, print nodes which are at K distance from the the given node.
Input format :

Line 1 : Elements in level order form (separated by space)

(If any node does not have left or right child, take -1 in its place)

Line 2 : Node

Line 3 : K

Output format : Answer nodes in different line

Sample Input :
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
3
1
Sample Output :
9
6
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
//code
#include<iostream>
using namespace std;

void printAtDepth(BinaryTreeNode<int>* root, int d){
    if(root == NULL)
        return;
    if(d == 0)
        cout<<root->data<<endl;
    printAtDepth(root->left, d-1);
    printAtDepth(root->right, d-1);
}

int nadrecursive(BinaryTreeNode<int>* root, int node, int k){
    if(root == NULL)
        return -1;
    
    //If current data is node, we print nodes at k depth
    if(root->data == node){
        printAtDepth(root, k);
        return 0;
    }
    
    //We  find depth of node to be printed wrt to root->left & root->right
    //If current node is at distance k, we print root->data
    int ld = nadrecursive(root->left, node, k);
    if(ld != -1){
        if(k-ld-2 >= 0)
            printAtDepth(root->right, k-ld-2);
        else if(k-ld-1 == 0)
            cout<<root->data<<endl;
    }
    int rd = nadrecursive(root->right, node, k);
    if(rd != -1){
        if(k-rd-2 >= 0)
            printAtDepth(root->left, k-rd-2);
        else if(k-rd-1 == 0)
            cout<<root->data<<endl;
    }
    
    //Returning distnace of node from current node
    if(ld==-1 && rd==-1)
        return -1;
    else if(ld == -1)
        return rd+1;
    else
        return ld+1;
}

void nodesAtDistanceK(BinaryTreeNode<int> *root, int node, int k) {
    int call = nadrecursive(root, node, k);
}




int main() {
    BinaryTreeNode<int>* root = takeInput();
    int targetNode, k;
    cin >> targetNode >> k;
    nodesAtDistanceK(root, targetNode, k);
    delete root;
}
