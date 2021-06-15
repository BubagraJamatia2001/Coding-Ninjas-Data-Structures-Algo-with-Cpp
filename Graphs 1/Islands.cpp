/*
Islands

An island is a small piece of land surrounded by water . A group of islands is said to be connected if we can reach from any given island 
to any other island in the same group . Given N islands (numbered from 1 to N) and two lists of size M (u and v) denoting island u[i] is 
connected to island v[i] and vice versa . Can you count the number of connected groups of islands.

Constraints :
1<=N<=100
1<=M<=(N*(N-1))/2
1<=u[i],v[i]<=N

Input Format :
Line 1 : Two integers N and M
Line 2 : List u of size of M
Line 3 : List v of size of M

Output Return Format :
The count the number of connected groups of islands

Sample Input :
2 1
1
2
Sample Output :
1 
*/

#include<iostream>
#include<vector>
using namespace std;

void DFS(int** G, bool* visited, int n, int sv){
    visited[sv] = true;
    for(int i=0; i<n; i++){
        if(i == sv)
            continue;
        if(!visited[i] && G[sv][i]==1)
        DFS(G, visited, n, i);
    }
}

int solve(int n,int m,vector<int>u,vector<int>v)
{
	int** G = new int* [n];
    for(int i=0; i<n; i++){
        G[i] = new int [n];
        for(int j=0; j<n; j++)
            G[i][j] = 0;
    }
    
    for(int i=0; i<m; i++){
        int ui = u[i] - 1;
        int vi = v[i] - 1;
        G[ui][vi] = 1;
        G[vi][ui] = 1;
    }
    
    bool* visited = new bool[n];
    for(int i=0; i<n; i++)
        visited[i] = false;
    
    int count = 0;
    for(int i=0; i<n; i++)
        if(!visited[i]){
            count++;
            DFS(G, visited, n, i);
        }
    return count;
}

int main()
{
	int n,m;
	vector<int>u,v;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int x;
		cin>>x;
		u.push_back(x);
	}
	for(int i=0;i<m;i++)
	{
		int x;
		cin>>x;
		v.push_back(x);
	}
	cout<<solve(n,m,u,v)<<endl;
}
