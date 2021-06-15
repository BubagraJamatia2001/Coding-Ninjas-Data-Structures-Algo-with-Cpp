/*
ZigZag tree

Given a binary tree, print the zig zag order i.e print level 1 from left to right, level 2 from right to left and so on. This means odd levels should get printed from left to right and even level right to left.
Input format :
Elements in level order form (separated by space)
(If any node does not have left or right child, take -1 in its place)
Output Format :
Elements are printed level wise, each level in new line (separated by space).

Sample Input :
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output :
5
10 6
2 3
9
*/
#include <iostream>
#include <queue>
#include <stack>

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

#include<queue>
#include<stack>
#include<iostream>
using namespace std;

void zigZagOrder(BinaryTreeNode<int> *root) {
    stack<BinaryTreeNode<int>*> S,S2;
    S.push(root);
    int flag=0;
    while(1) {
        BinaryTreeNode<int> *temp;
        if(flag==0) {
            if(S.size()==0) {
                flag=1;
                cout<<endl;
                if(S2.size()==0)
                    return;
            }
            else {
                temp=S.top();
                S.pop();
                cout<<temp->data<<" ";
                if(temp->left!=NULL)
                    S2.push(temp->left);
                if(temp->right!=NULL)
                    S2.push(temp->right);
            }
        }
        if(flag==1) {
            if(S2.size()==0) {
                flag=0;
                cout<<endl;
                if(S.size()==0)
                    return;
            }
            else {
                temp=S2.top();
                S2.pop();
                cout<<temp->data<<" ";
                if(temp->right!=NULL)
                    S.push(temp->right);
                if(temp->left!=NULL)
                    S.push(temp->left);
            }
        }
    }
}


int main() {
    BinaryTreeNode<int>* root = takeInput();
    zigZagOrder(root);
}
