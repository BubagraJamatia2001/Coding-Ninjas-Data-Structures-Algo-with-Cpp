/*
Pair sum in a BST

Given a binary search tree and an integer S, find pair of nodes in the BST which sum to S. You can use extra space only O(log n).
Assume BST contains all unique elements.
Note: In a pair, print the smaller element first.
Input format:

Line 1: Elements in the level order form (separated by space)

(If any node does not have left or right child, take -1 in its place)

Line 2: S

Output format: Each pair in a different line (pair elements separated by space)

Sample Input :
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
12
Sample Output
2 10
5 7

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

void printLevelATNewLine(BinaryTreeNode<int> *root) {
	queue<BinaryTreeNode<int>*> q;
	q.push(root);
	q.push(NULL);
	while(!q.empty()) {
		BinaryTreeNode<int> *first = q.front();
		q.pop();
		if(first == NULL) {
			if(q.empty()) {
				break;
			}
			cout << endl;
			q.push(NULL);
			continue;
		}
		cout << first -> data << " ";
		if(first -> left != NULL) {
			q.push(first -> left);
		}
		if(first -> right != NULL) {
			q.push(first -> right);
		}
	}
}
//code
#include <stack>

//Returning total number of nodes.
int count(BinaryTreeNode<int>* root){
    if(root == NULL)
        return 0;
    return 1 + count(root->left) + count(root->right);
}

//Finding right most node and adding nodes in path while doing so
void rightTraversal(BinaryTreeNode<int>* root, stack<BinaryTreeNode<int>*>* st){
    if(root == NULL)
        return;
    st->push(root);
    rightTraversal(root->right, st);
}

void leftTraversal(BinaryTreeNode<int>* root, stack<BinaryTreeNode<int>*>* st){
    if(root == NULL)
        return;
    st->push(root);
    leftTraversal(root->left, st);
}

void printNodesSumToS(BinaryTreeNode<int> *root, int s) {
    int size = count(root);
    int i = 1;
    
    //Inorder and Rev.Inorder stack to have min and max elements.
    stack<BinaryTreeNode<int>*>* in = new stack<BinaryTreeNode<int>*>;
    stack<BinaryTreeNode<int>*>* revin = new stack<BinaryTreeNode<int>*>;
    leftTraversal(root, in);
    rightTraversal(root, revin);
    while(i<size){
        BinaryTreeNode<int>* left = in->top();
        BinaryTreeNode<int>* right = revin->top();
        int sum = left->data + right->data;
        if(sum == s){
            cout<<left->data<<" "<<right->data<<endl;
            in->pop();
            revin->pop();
            i += 2;
            
            //Finding next smallest and largest elements
            leftTraversal(left->right, in);
            rightTraversal(right->left, revin);
        }
        else if(sum<s){
            in->pop();
            i++;
            leftTraversal(left->right, in);
        }
        else{
            revin->pop();
            i++;
            rightTraversal(right->left, revin);
        }
    }
    delete in;
    delete revin;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    int s;
    cin >> s;
    printNodesSumToS(root, s);
    delete root;
}
