/*
Code : Prim's Algorithm

Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the Minimum Spanning Tree (MST) using Prim's algorithm.
For printing MST follow the steps -
1. 
In one line, print an edge which is part of MST in the format -
v1 v2 w
where, v1 and v2 are the vertices of the edge which is included in MST and whose weight is w. And v1 <= v2 i.e. print the smaller vertex first while printing an edge.
2. Print V-1 edges in above format in different lines.
Note : Order of different edges doesn't matter.

Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)

Output Format :
MST

Constraints :
2 <= V, E <= 10^5

Sample Input 1 :
4 4
0 1 3
0 3 5
1 2 1
2 3 8

Sample Output 1 :
0 1 3
1 2 1
0 3 5

*/

#include <bits/stdc++.h>
using namespace std;

int findmin(bool* visited, int* weights, int V){
    int vertex, maxweight=INT_MAX;
    for(int i=0; i<V; i++)
        if(!visited[i] && weights[i]<maxweight){
            vertex = i;
            maxweight = weights[i];
        }
    return vertex;
}

int main()
{
    int V, E;
    cin >> V >> E;
    
    int **G = new int*[V];
    for(int i=0; i<V; i++){
        G[i] = new int[V];
        for(int j=0; j<V; j++)
            G[i][j] = 0;            //CANNOT BE -1???
    }
    
    for(int i=0; i<E; i++){
        int s, d, w;
        cin>>s>>d>>w;
        G[s][d] = w;
        G[d][s] = w;
    }
    
    bool* visited = new bool[V];
    int* parents = new int[V];
    int* weights = new int[V];
    for(int i=0; i<V; i++){
        weights[i] = INT_MAX;
        visited[i] = false;
    }
    weights[0] = 0;
    
    for(int i=0; i<V; i++){
        int vertex = findmin(visited, weights, V);
        visited[vertex] = true;
        // VISITING UNVISITED NODES
        for(int j=0; j<V; j++){
            if(G[vertex][j]!=0 && !visited[j] && weights[j]>G[vertex][j]){
                weights[j] = G[vertex][j];
                parents[j] = vertex;
            }
        }
    }

    for(int i=1; i<V; i++)
        cout<<min(i,parents[i])<<" "<<max(i,parents[i])<<" "<<weights[i]<<endl;
    
    for(int i=0; i<V; i++)
        delete [] G[i];
    delete [] G;
    delete [] visited;
    delete [] weights;
    delete [] parents;
    
    return 0;
}
