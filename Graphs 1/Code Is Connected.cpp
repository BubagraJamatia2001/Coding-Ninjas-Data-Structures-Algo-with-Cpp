/*
Code : Is Connected ?

Given an undirected graph G(V,E), check if the graph G is connected graph or not.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.

Input Format :
Line 1: Two Integers V and E (separated by space)
Next 'E' lines, each have two space-separated integers, 'a' and 'b', denoting that there exists an edge between Vertex 'a' and Vertex 'b'.

Output Format :
"true" or "false"

Constraints :
2 <= V <= 1000
1 <= E <= 1000

Sample Input 1:
4 4
0 1
0 3
1 2
2 3

Sample Output 1:
true

Sample Input 2:
4 3
0 1
1 3 
0 3

Sample Output 2:
false 

Sample Output 2 Explanation
The graph is not connected, even though vertices 0,1 and 3 are connected to each other but there isn’t any path from vertices 0,1,3 to vertex 2. 
*/
#include <iostream>
using namespace std;

void DFStraversal(int** G, bool* visited, int s, int n){
    visited[s] = true;
    for(int i=0; i<n; i++){
        if(i == s)
            continue;
        if(G[s][i] == 1 && !visited[i])
            DFStraversal(G, visited, i, n);
    }
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
    
    bool* visited = new bool [V];
    for(int i=0; i<V; i++)
        visited[i] = false;

    DFStraversal(G, visited, 0, V);
    
    for(int i=0; i<V ;i++){
        delete [] G[i];
    }
    delete [] G;
    
    for(int i=0; i<V; i++)
        if(!visited[i]){
            cout << "false";
            delete [] visited;
            return 0;
        }
    
    delete [] visited;
    cout << "true";
    
    return 0;
}
