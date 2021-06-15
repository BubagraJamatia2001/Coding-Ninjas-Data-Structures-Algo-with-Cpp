/*
Pair sum BInary Tree

Given a binary tree and an integer S, print all the pair of nodes whose sum equals S.
Assume binary tree contains all unique elements.
Note : In a pair, print the smaller element first. Order of different pair doesn't matter.
Input format :
Line 1 : Elements in level order form (separated by space)
(If any node does not have left or right child, take -1 in its place)
Line 2 : Integer S
Output Format :
Each pair in different line (pair elements separated by space)
Constraints :
1 <= N <= 1000
Sample Input 1:
5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
15
Sample Output 1:
5 10
6 9
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
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void array(BinaryTreeNode<int>* root,vector<int>* V){
    if(root==NULL)
        return;
    V->push_back(root->data);
    array(root->left,V);
    array(root->right,V);
}

void nodesSumToS(BinaryTreeNode<int> *root, int sum) {
    vector<int>* V = new vector<int>;
    array(root, V);
    sort(V->begin(), V->end());
    vector<int>::iterator start, end;
    start = V->begin();
    end = V->end();
    end--;
    while(start<end){
        int _sum = *start + *end;
        if(_sum == sum){
            cout<<*start<<" "<<*end<<endl;
            start++;
            end--;
        }
        else if(_sum > sum)
            end--;
        else
            start++;
    }
    delete V;
}
