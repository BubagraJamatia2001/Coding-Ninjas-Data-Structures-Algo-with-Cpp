/*
Code : Min Cost Path

Given an integer matrix of size m*n, you need to find out the value of minimum cost to reach from the cell (0, 0) to (m-1, n-1).
From a cell (i, j), you can move in three directions : (i+1, j), (i, j+1) and (i+1, j+1).
Cost of a path is defined as the sum of values of each cell through which path passes.

Input Format :
Line 1 : Two integers, m and n
Next m lines : n integers of each row (separated by space)

Output Format :
Minimum cost

Constraints :
1 <= m, n <= 20

Sample Input 1 :
3 4
3 4 1 2
2 1 8 9
4 7 8 1

Sample Output 1 :
13
*/

#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int helper(int** input, int m, int n, int x, int y){
    if(x==m-1 && y==n-1)
        return input[x][y];
    if(x>=m || y>=n)
        return INT_MAX;
    int a = helper(input, m, n, x, y+1);
    int b = helper(input, m, n, x+1, y+1);
    int c = helper(input, m, n, x+1, y);
    return input[x][y] + min(a,min(b,c));
}

int minCostPath(int **input, int m, int n) {
    return helper(input, m, n, 0, 0) ; 
}
int main() {
    int **arr,n,m;
    cin >> n >> m;
    arr = new int*[n];
    for(int i = 0; i < n; i++) {
        arr[i] = new int[m];
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    cout << minCostPath(arr, n, m) << endl;
}
