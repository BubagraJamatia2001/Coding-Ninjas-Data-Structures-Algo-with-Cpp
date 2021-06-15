/*
Structurally identical

Given two Generic trees, return true if they are structurally identical i.e. they are made of nodes with the same values arranged in the same way.

Input format :
Line 1 : Tree 1 elements in level order form separated by space (as per done in class). Order is - 
Root_data, n (No_Of_Child_Of_Root), n children, and so on for every element 
Line 2 : Tree 2 elements in level order form separated by space (as per done in class). Order is - 
Root_data, n (No_Of_Child_Of_Root), n children, and so on for every element 

Output format :
true or false

Sample Input 1 :
10 3 20 30 40 2 40 50 0 0 0 0 
10 3 20 30 40 2 40 50 0 0 0 0

Sample Output 1 :
true

Sample Input 2 :
10 3 20 30 40 2 40 50 0 0 0 0 
10 3 2 30 40 2 40 50 0 0 0 0

Sample Output 2:
false
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
bool isIdentical(TreeNode<int> *root1, TreeNode<int> *root2) {
    if(root1->data != root2->data)
        return false;
    if(root1->children.size()!=root2->children.size())
        return false;
    for(int i=0;i<root1->children.size();i++)
        if(isIdentical(root1->children[i],root2->children[i])==false) {
            return false;
    }
    return true;
}
//The Solution

int main() {
    TreeNode<int>* root1 = takeInputLevelWise();
    TreeNode<int>* root2 = takeInputLevelWise();
    if(isIdentical(root1, root2)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}
