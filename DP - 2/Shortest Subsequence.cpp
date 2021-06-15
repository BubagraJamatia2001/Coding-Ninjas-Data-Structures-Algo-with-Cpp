/*
Shortest Subsequence

Gary has two string S and V. Now Gary wants to know the length shortest subsequence in S such that it is not a subsequence in V.
Note: input data will be such so there will always be a solution.

Input Format :
Line 1 : String S of length N (1 <= N <= 1000)
Line 2 : String V of length M (1 <= M <= 1000)

Output Format :
Length of shortest subsequence in S such that it is not a subsequence in V

Sample Input :
babab
babba

Sample Output :
3
*/

#include<bits/stdc++.h>
using namespace std;
int solve(string S, string V) {
    
    int dp[S.size()+1][V.size()+1]; 

    for (int i = 0; i <= S.size(); i++) 
        dp[i][0] = 1; 
    
    for (int i = 0; i <= V.size(); i++) 
        dp[0][i] = INT_MAX-1; 
  
    for (int i = 1; i <= S.size(); i++) 
    { 
        for (int j = 1; j <= V.size(); j++) 
        { 
            char ch = S[i-1]; 
            int k; 
            for (k = j-1; k >= 0; k--) 
                if (V[k] == ch) 
                    break; 
  
            // char not present in T 
            if (k == -1) 
                dp[i][j] = 1; 
            else
               dp[i][j] = min(dp[i-1][j], dp[i-1][k] + 1); 
        } 
    } 
  
    int ans = dp[S.size()][V.size()]; 
  
    return ans; 
}
int main()
{
	string S,V;
	cin>>S>>V;
	cout<<solve(S,V)<<endl;
	return 0;
}
