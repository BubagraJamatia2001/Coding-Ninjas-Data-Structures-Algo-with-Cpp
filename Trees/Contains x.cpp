/*
Contains x

Given a generic tree and an integer x, check if x is present in the given tree or not. Return true if x is present, return false otherwise.
Input format :
Line 1 : Integer x
Line 2 : Elements in level order form separated by space (as per done in class). Order is - 
Root_data, n (No_Of_Child_Of_Root), n children, and so on for every element 
Output format :
true or false
Sample Input 1 :
40
10 3 20 30 40 2 40 50 0 0 0 0 
Sample Output 1 :
true
Sample Input 2 :
4
10 3 20 30 40 2 40 50 0 0 0 0 
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
bool containsX(TreeNode<int>* root, int x) {
    if(root->data == x)
        return true;
    for(int i=0;i<root->children.size();i++) {
        if(containsX(root->children[i],x)==true)
            return true;
    }
    return false;
}
//The Solution

int main() {
    int x;
    cin >> x;
    TreeNode<int>* root = takeInputLevelWise();
    if(containsX(root, x)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}
