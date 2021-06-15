/*
Code : Has Path

Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), check if there exists any path between them or not. Print true or false.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.

Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Two integers a and b, denoting that there exists an edge between vertex a and vertex b (separated by space)
Line (E+2) : Two integers v1 and v2 (separated by space)

Output Format :
true or false

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
true

Sample Input 2 :
6 3
5 3
0 1
3 4
0 3

Sample Output 2 :
false
*/

#include <iostream>
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
    
    if(G[s][e] == 1)
        flag = 1;
    
    bool* visited = new bool [V];
    for(int i=0; i<V; i++)
        visited[i] = false;
    
    queue<int> list;
    list.push(s);
    visited[s] = true;
    while(!list.empty()){
        int ele = list.front();
        list.pop();
        for(int j=0; j<V; j++){
            if(j == ele)
                continue;
            if(G[ele][j] == 1){
                if(visited[j])
                    continue;
                list.push(j);
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
    
    if(flag)
        cout << "true";
    else
        cout << "false";
    return 0;
}
