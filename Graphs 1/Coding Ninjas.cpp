/*
Coding Ninjas

Given a NxM matrix containing Uppercase English Alphabets only. Your task is to tell if there is a path in the given matrix which makes the sentence “CODINGNINJA” .
There is a path from any cell to all its neighbouring cells. A neighbour may share an edge or a corner.
Input Format :
Line 1 : Two space separated integers N  and M, where N is number of rows and M is number of columns in the matrix.
Next N lines : N rows of the matrix. First line of these N line will contain 0th row of matrix, second line will contain 1st row and so on
Assume input to be 0-indexed based
Output Format :
Return 1 if there is a path which makes the sentence “CODINGNINJA” else return 0.
Constraints :
1 <= N <= 100
1 <= M <= 100
Sample Input :
2 11
CXDXNXNXNXA
XOXIXGXIXJX
Sample Output :
1
*/

#include<bits/stdc++.h>
using namespace std;
#define MAXN 102
bool check(char Graph[102][102], int x, int y, char* arr, int n, int m){
    if(arr[0] == '\0')
        return true;
    char temp = Graph[x][y];
    Graph[x][y] = 'X';
    
    if(x-1>-1 && x-1<m && y+1>-1 && y+1<m)
        if(Graph[x-1][y+1] == arr[0])
            if(check(Graph, x-1, y+1, arr+1, n, m))
                return true;
    
    if(x>-1 && x<m && y+1>-1 && y+1<m)
        if(Graph[x][y+1] == arr[0])
            if(check(Graph, x, y+1, arr+1, n, m))
                return true;
    
    if(x+1>-1 && x+1<m && y+1>-1 && y+1<m)
        if(Graph[x+1][y+1] == arr[0])
            if(check(Graph, x+1, y+1, arr+1, n, m))
                return true;
    
    if(x-1>-1 && x-1<m && y>-1 && y<m)
        if(Graph[x-1][y] == arr[0])
            if(check(Graph, x-1, y, arr+1, n, m))
                return true;
    
    if(x+1>-1 && x+1<m && y>-1 && y<m)
        if(Graph[x+1][y] == arr[0])
            if(check(Graph, x+1, y, arr+1, n, m))
                return true;
    
    if(x-1>-1 && x-1<m && y-1>-1 && y-1<m)
        if(Graph[x-1][y-1] == arr[0])
            if(check(Graph, x-1, y-1, arr+1, n, m))
                return true;
    
    if(x>-1 && x<m && y-1>-1 && y-1<m)
        if(Graph[x][y-1] == arr[0])
            if(check(Graph, x, y-1, arr+1, n, m))
                return true;
    
    if(x+1>-1 && x+1<m && y-1>-1 && y-1<m)
        if(Graph[x+1][y-1] == arr[0])
            if(check(Graph, x+1, y-1, arr+1, n, m))
                return true;
    
    Graph[x][y] = temp;
    return false;
}

int solve(char Graph[][MAXN],int n, int m){
	char arr[] = "ODINGNINJA";
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(Graph[i][j] == 'C')
                if(check(Graph, i, j, arr, n, m))
                    return 1;
    return 0;
}

int main()
{
	int N,M,i;
	char Graph[MAXN][MAXN];
	cin>>N>>M;
	for(i = 0;i < N; i++){
		cin>>Graph[i];
	}
	cout<<solve(Graph,N,M)<<endl;
}
