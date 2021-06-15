/*
Matrix Chain Multiplication

Given a chain of matrices A1, A2, A3,.....An, you have to figure out the most efficient way to multiply these matrices i.e. determine where to 
place parentheses to minimise the number of multiplications.
You will be given an array p[] of size n + 1. Dimension of matrix Ai is p[i - 1]*p[i]. You need to find minimum number of multiplications needed 
to multiply the chain.

Input Format :
Line 1 : Integer n i.e. number of matrices
Line 2 : n + 1 integers i.e. elements of array p[] 

Output Format :
Line 1 : Minimum number of multiplication needed

Constraints :
1 <= n <= 100

Sample Input 1 :
3
10 15 20 25

Sample Output :
8000

Sample Output Explanation :
There are two ways to multiply the chain - A1*(A2*A3) or (A1*A2)*A3.
If multiply in order A1*(A2*A3) then number of multiplications required are 15000.
If multiply in order (A1*A2)*A3 then number of multiplications required are 8000.
Thus minimum number of multiplications required are 8000
*/

#include<bits/stdc++.h>
using namespace std;

int helper(int* arr, int si, int ei, int size, int* dp) {
    
    //Base Case: If there are one or two values signifying one matrix only - no calc required
    if(si==ei || si==ei-1)
        return 0;
    
    if(dp[si+(size*ei)] != -1)
        return dp[si+(size*ei)];
    
    int min = INT_MAX;
    
    //Putting brackets everywhere and doing small calc and finding min steps
    for(int i=si+1; i<=ei-1; i++){
        int op = helper(arr, si, i, size, dp) + helper(arr, i, ei, size, dp) + arr[si]*arr[i]*arr[ei];
        min = (min>op) ? op : min;
    }
    
    dp[si+(size*ei)] = min;
    
    return min;
}

int mcm(int* p, int n){
    
    int* dp = new int[(n+1)*(n+1)];
    for(int i=0; i<(n+1)*(n+1); i++)
        dp[i] = -1;
    int ans = helper(p, 0, n, n+1, dp);
    delete [] dp;
    return ans;
}
int main(){

  int n; 
  cin >> n;
  int* p = new int[n];

  for(int i = 0; i <= n; i++){
    cin >> p[i];
  }

  cout << mcm(p, n);

}


