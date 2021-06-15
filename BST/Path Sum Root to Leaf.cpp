/*
Path Sum Root to Leaf

Given a binary tree and a number k, print out all root to leaf paths where the sum of all nodes value is same as the given number k.
Input format :

Line 1 : Elements in level order form (separated by space)

(If any node does not have left or right child, take -1 in its place)

Line 2 : k

Output format : Print each path in new line, elements separated by space

Sample Input 1 :
5 6 7 2 3 -1 1 -1 -1 -1 9 -1 -1 -1 -1
13
Sample Output 1 :
5 6 2
5 7 1
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

#include<vector>

void helper(BinaryTreeNode<int>* root, int k, vector<int> vc){
    if(root->left==NULL && root->right==NULL && root->data==k){
        for(int i=0; i<vc.size(); i++)
            cout<<vc[i]<<" ";
        cout<<root->data<<endl;
    }
    vc.push_back(root->data);
    if(root->left != NULL)
        helper(root->left, k-root->data, vc);
    if(root->right != NULL)
        helper(root->right, k-root->data, vc);
}

void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k){
    vector<int> vc;
    helper(root, k, vc);
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    int k;
    cin >> k;
    rootToLeafPathsSumToK(root, k);
    delete root;
}
