/*
Code : Kruskal's Algorithm

Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the Minimum Spanning Tree (MST) using Kruskal's algorithm.
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
1 2 1
0 1 3
0 3 5
*/

#include <bits/stdc++.h>
using namespace std;

class edge{
    public:
    
    int s, d, w;
    
    bool operator< (const edge& e) const{
        return w < e.w;
    }
    
    void print(){
        cout << min(s, d)  << " " << max(s,d)<< " " << w << endl;
    }
    
};

int findparent(int v, int* parents){
    if(v == parents[v])
        return v;
    return findparent(parents[v], parents);
}

int main()
{
    int V, E;
    cin >> V >> E;
    vector<edge> input, output;
    
    for(int i=0; i<E; i++){
        edge e;
        cin >> e.s >> e.d >> e.w;
        input.push_back(e);
    }
    
    sort(input.begin(), input.end());
    
    int* parents = new int[V];
    for(int i=0; i<V; i++)
        parents[i] = i;
    int i=0, count=0;
    
    while(count < V-1){
        edge e = input[i];
        i++;
        int pofs = findparent(e.s, parents);
        int pofd = findparent(e.d, parents);
        if(pofs == pofd)
            continue;
        output.push_back(e);
        count++;
        parents[pofs] = pofd; //C
    }
    
    for(auto it=output.begin(); it!=output.end(); it++)
        (*it).print();
    
    delete [] parents;
    
    return 0;
}
