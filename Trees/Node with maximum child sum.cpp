/*
Node with maximum child sum

Given a tree, find and return the node for which sum of data of all children and the node itself is maximum. In the sum, data of node itself and data of 
immediate children is to be taken.

Input format :
Line 1 : Elements in level order form separated by space (as per done in class). Order is - 
Root_data, n (No_Of_Child_Of_Root), n children, and so on for every element 

Output format :
Node with maximum sum.

Sample Input 1 :
5 3 1 2 3 1 15 2 4 5 1 6 0 0 0 0

Sample Output 1 :
1
*/

#include <iostream>
using namespace std;
#include <vector>

template <typename T>
class TreeNode {
public:
    T data;
    vector<TreeNode<T>*> children;
    
    TreeNode(T data) {
        this->data = data;
    }
    
    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
    
};


#include <queue>
#include "solution.h"

TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    
    queue<TreeNode<int>*> pendingNodes;
    
    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}
//The Solution

TreeNode<int>* maxSumNode(TreeNode<int> *root){
    int sum=root->data;
    TreeNode<int>* FinalNode=root;
    for(int i=0;i<root->children.size();i++) {
        sum+=root->children[i]->data;
    }
    for(int i=0;i<root->children.size();i++) {
        TreeNode<int>* tempnode = maxSumNode(root->children[i]);
        int tempsum = tempnode->data;
        for(int j=0;j<tempnode->children.size();j++) {
            tempsum+=tempnode->children[j]->data;
        }
        if(sum<tempsum) {
            FinalNode = tempnode;
            sum = tempsum;
        }
    }
    return FinalNode;
}

//The Solution

int main() {
    TreeNode<int>* root = takeInputLevelWise();
    TreeNode<int>* ans = maxSumNode(root);
    if(ans != NULL) {
        cout << ans -> data << endl;
    }
}


