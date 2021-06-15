/*
Code : Get Path - DFS

Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), find and print the path from v1 to v2 (if exists). 
Print nothing if there is no path between v1 and v2.
Find the path using DFS and print the first path that you encountered.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.
Note : Save the input graph in Adjacency Matrix.

Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Two integers a and b, denoting that there exists an edge between vertex a and vertex b (separated by space)
Line (E+2) : Two integers v1 and v2 (separated by space)

Output Format :
Path from v1 to v2 in reverse order (separated by space)

Constraints :
2 <= V <= 1000
1 <= E <= 1000
0 <= v1, v2 <= V-1

Sample Input 1 :
4 4
0 1
0 3
1 2
2 3
1 3

Sample Output 1 :
3 0 1
*/

#include <iostream>
#include<vector>
using namespace std;

vector<int> getpath(int** G, bool* visited, int s, int e, int n){
    if(s == e){
        vector<int> path;
        visited[e] = true;
        path.push_back(s);
        return path;
    }
    visited[s] = true;
    vector<int> path;
    for(int i=0; i<n; i++){
        if(i == s)
            continue;
        if(G[s][i] == 1 && !visited[i])
            path = getpath(G, visited, i, e, n);
        if(path.size()!= 0)
            break;
    }
    if(path.size() != 0)
        path.push_back(s);
    return path;
}

int main()
{
    int V, E, tempX, tempY;
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
    
    int s, e;
    cin >> s >> e;
    
    bool* visited = new bool [V];
    for(int i=0; i<V; i++)
        visited[i] = false;
    
    vector<int> path = getpath(G, visited, s, e, V);
    
    delete [] visited;
    for(int i=0; i<V ;i++){
        delete [] G[i];
    }
    delete [] G;
    
    if(path.size())
        for(int i=0; i<path.size(); i++)
            cout << path[i] << " ";
    
    return 0;
}
