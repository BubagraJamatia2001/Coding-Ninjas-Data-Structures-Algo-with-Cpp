/*
Code : Get Path - BFS

Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), find and print the path from v1 to v2 (if exists).
Print nothing if there is no path between v1 and v2.
Find the path using BFS and print the shortest path available.
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
#include<unordered_map>
#include<queue>
using namespace std;

int main() {
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
    
    int s, e;
    cin >> s >> e;
    
    int flag = 0;
    
    bool* visited = new bool [V];
    for(int i=0; i<V; i++)
        visited[i] = false;
    
    queue<int> list;
    unordered_map<int,int> map;
    list.push(s);
    visited[s] = true;
    while(!list.empty()){
        int ele = list.front();
        list.pop();
        for(int j=0; j<V; j++){
            if(j == ele)
                continue;
            if(G[ele][j] == 1 && !visited[j]){
                list.push(j);
                map[j] = ele;
                visited[j] = true;
                if(j == e){
                    flag = 1;
                    break;
                }
            }
        }
    }
    
    delete [] visited;
    for(int i=0; i<V ;i++){
        delete [] G[i];
    }
    delete [] G;
    
    if(flag){
        cout << e << " ";
        int node = e;
        while(1){
            if(map.count(node)<1)
                break;
            cout << map[node] << " ";
            node = map[node];
        }
    }
    
    return 0;
}

