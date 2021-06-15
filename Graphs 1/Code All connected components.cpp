/*
Code : All connected components

Given an undirected graph G(V,E), find and print all the connected components of the given graph G.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
You need to take input in main and create a function which should return all the connected components. And then print them in the main, not inside function.
Print different components in new line. And each component should be printed in increasing order (separated by space). Order of different components doesn't matter.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next 'E' lines, each have two space-separated integers, 'a' and 'b', denoting that there exists an edge between Vertex 'a' and Vertex 'b'.
Output Format :
Different components in new line
Constraints :
2 <= V <= 1000
1 <= E <= 1000
Sample Input 1:
4 2
0 1
2 3
Sample Output 1:
0 1 
2 3 
Sample Input 2:
4 3
0 1
1 3 
0 3
Sample Output 2:
0 1 3 
2
*/
#include<iostream>
#include<set>
#include<vector>
using namespace std;

void helper(int** G, bool* visited, int V, int sv, set<int>& component){
    visited[sv] = true;
    component.insert(sv);
    for(int i=0; i<V; i++){
        if(i == sv)
            continue;
        if(G[sv][i] == 1 && !visited[i])
            helper(G, visited, V, i, component);    
    }
}

int main()
{
    int V, E;
    cin >> V >> E;
    
    int** G = new int* [V];
    for(int i=0; i<V; i++){
        G[i] = new int [V];
        for(int j=0; j<V; j++)
            G[i][j] = 0;
    }
    
    for(int i=0; i<E; i++){
        int e1, e2;
        cin >> e1 >> e2;
        G[e1][e2] = 1;
        G[e2][e1] = 1;
    }
    
    bool* visited = new bool [V];
    for(int i=0; i<V; i++)
        visited[i] = false;
    
    vector<set<int>> list;
    for(int i=0; i<V; i++){
        if(!visited[i]){
            set<int> component; 
            helper(G, visited, V, i, component);
            list.push_back(component);
        }
    }
    
    delete [] visited;
    for(int i=0; i<V ;i++){
        delete [] G[i];
    }
    delete [] G;
    
    vector<set<int>>::iterator it;
    for(it=list.begin(); it!=list.end(); it++){
        set<int> comp = *it;
        set<int>::iterator st;
        for(st=comp.begin(); st!=comp.end(); st++){
            cout << *st << " ";
        }
        cout << endl; 
    }
        
    return 0;
}
