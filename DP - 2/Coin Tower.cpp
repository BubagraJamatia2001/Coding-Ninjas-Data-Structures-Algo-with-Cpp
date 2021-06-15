/*
Coin Tower

Whis and Beerus are playing a new game today . They form a tower of N coins and make a move in alternate turns . Beerus being the God plays first . 
In one move player can remove 1 or X or Y coins from the tower . The person to make the last move wins the Game . Can you find out who wins the game ?
Input Format :
Contains three value N,X,Y as mentioned in the problem statement
Output Format :
A string containing the name of the winner like “Whis” or “Beerus” (without quotes)
Constraints:
1<=N<=10^6
2<=X<=Y<=50
Sample Input :
 4 2 3
Sample Output :
 Whis
*/

#include<bits/stdc++.h>
using namespace std;

string solve(int n, int x, int y) {
	int* dp = new int[n+1];
    dp[1] = 1;
    if(x<=n)
        dp[x] = 1;
    if(y<=n)
        dp[y] = 1;
    for(int i=2; i<=n; i++){
        if(i==x || i==y)
            continue;
        int a,b,c;
        a=b=c=INT_MIN;
        a = dp[i-1]^1;
        if(i-x >= 1)
            b = dp[i-x]^1;
        if(i-y >= 1)
            c = dp[i-y]^1;
        dp[i] = max(a, max(b, c));
    }
    if(dp[n] == 1)
        return "Beerus";
    else
        return "Whis";
}

int n,x,y;
int main()
{
	cin>>n>>x>>y;
	cout<<solve(n,x,y)<<endl;
}
