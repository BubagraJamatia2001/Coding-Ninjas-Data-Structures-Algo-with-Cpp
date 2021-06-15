/*
Second Largest Element In Tree

Given a generic tree, find and return the node with second largest value in given tree. Return NULL if no node with required value is present.
Input format :
Line 1 : Elements in level order form separated by space (as per done in class). Order is -
Root_data, n (No_Of_Child_Of_Root), n children, and so on for every element 
Output Format :
Second Largest node data
Sample Input 1 :
10 3 20 30 40 2 40 50 0 0 0 0 
Sample Output 1 :
40
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
#include <climits>

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

class Pair {
    public:
    TreeNode<int>* Max;
    TreeNode<int>* SM;
    Pair() {
        Max=NULL;
        SM=NULL;
    }
};

Pair SL(TreeNode<int>* root) {
    Pair P;
    P.Max=root;
    for(int i=0;i<root->children.size();i++) {
        Pair PNew=SL(root->children[i]);
        if(PNew.Max->data > P.Max->data) {
            TreeNode<int>* temp=P.Max;
            P.Max=PNew.Max;
            if(PNew.SM==NULL)
                P.SM=temp;
            else if(temp->data > PNew.SM->data)
                P.SM=temp;
            else
                P.SM=PNew.SM;
        }
        else if(PNew.Max->data == P.Max->data) {
            continue;
        }
        else {
            if(P.SM==NULL)
                P.SM=PNew.Max;
            else if(PNew.Max->data > P.SM->data)
                P.SM=PNew.Max;
        }
    }
    return P;
}

TreeNode <int>* secondLargest(TreeNode<int> *root) {
    Pair Ans = SL(root);
    return Ans.SM;
}
//The Solution


int main() {
    TreeNode<int>* root = takeInputLevelWise();
    TreeNode<int>* ans = secondLargest(root);
    if(ans == NULL) {
        cout << INT_MIN << endl;
    }
    else {
        cout << ans -> data << endl;
    }
}
