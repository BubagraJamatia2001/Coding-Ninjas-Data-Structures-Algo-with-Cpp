/*
Level wise linkedlist

Given a binary tree, write code to create a separate linked list for each level. You need to return the array which contains head of each level linked list.
Input format :

Elements in level order form (separated by space). If any node does not have left or right child, take -1 in its place.

Output format : Each level linked list is printed in new line (elements separated by space).

Sample Input :
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output :
5 
6 10 
2 3 
9
*/

#include <iostream>
#include <vector>
#include <queue>

template <typename T>
class node{
public:
    T data;
    node<T> * next;
    node(T data){
        this->data=data;
        this->next=NULL;
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

void print(node<int> *head)
{
    node<int> *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
//code

#include<queue>
#include<vector>

using namespace std;

vector<node<int>*> createLLForEachLevel(BinaryTreeNode<int> *root) {
    queue<BinaryTreeNode<int>*> Q;
    vector<node<int>*> V;
    node<int> *head=NULL, *tail=NULL;
    Q.push(root);
    Q.push(NULL);
    while(Q.size()) {
        BinaryTreeNode<int> *temp = Q.front();
        Q.pop();
        if(temp==NULL) {
            V.push_back(head);
            if(Q.size()==0)
                break;
            Q.push(NULL);
            head=tail=NULL;
            continue;
        }
        if(temp->left != NULL) 
            Q.push(temp->left);
        if(temp->right != NULL)
            Q.push(temp->right);
        node<int> *newnode = new node<int>(temp->data);
        if(head==NULL)
            head=tail=newnode;
        else{
            tail->next=newnode;
            tail=newnode;
        }
    }
    return V;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    vector<node<int>*> ans = createLLForEachLevel(root);
    for(int i = 0; i < ans.size(); i++) {
	    print(ans[i]);
    }
}
