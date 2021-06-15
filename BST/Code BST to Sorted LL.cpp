/*
Code: BST to Sorted LL

Given a BST, convert it into a sorted linked list. Return the head of LL.
Input format :
Elements in level order form (separated by space)
(If any node does not have left or right child, take -1 in its place)
Output Format :
Linked list elements (separated by space)
Sample Input :
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
Sample Output :
2 5 6 7 8 10
*/

#include <iostream>
#include <queue>

template <typename T>
class Node{
public:
    T data;
    Node<T> *next;
    Node(T data){
        this -> data = data;
        this -> next = NULL;
    }
};

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

class Pair {
    public:
    Node<int> *head, *tail;
};

Pair BSTtoLL(BinaryTreeNode<int>* root) {
    if(root==NULL) {
        Pair P;
        P.head=P.tail=NULL;
        return P;
    }
    Pair left = BSTtoLL(root->left);
    Pair right = BSTtoLL(root->right);
    Node<int>* newNode = new Node<int>(root->data);
    Pair mid;
    mid.head = newNode;
    mid.tail = mid.head;
    if(left.head!=NULL)
        left.tail->next=mid.head;
    if(right.head!=NULL)
        mid.tail->next=right.head;
    Pair answer;
    if(left.head==NULL)
        answer.head=mid.head;
    else
        answer.head=left.head;
    if(right.head==NULL)
        answer.tail=mid.tail;
    else
        answer.tail=right.tail;
    return answer;
}

Node<int>* constructBST(BinaryTreeNode<int>* root) {
    return BSTtoLL(root).head;
}


int main() {
    BinaryTreeNode<int>* root = takeInput();
    Node<int>* head = constructBST(root);
    while(head != NULL) {
        cout << head -> data << " ";
        head = head -> next;
    }
    
}
