/*
Ways To Make Coin Change

You are given an infinite supply of coins of each of denominations D = {D0, D1, D2, D3, ...... Dn-1}. You need to figure out the total number of ways W, 
in which you can make change for Value V using coins of denominations D.
Note : Return 0, if change isn't possible.

Input Format
Line 1 : Integer n i.e. total number of denominations
Line 2 : N integers i.e. n denomination values
Line 3 : Value V

Output Format
Line 1 :  Number of ways i.e. W

Constraints :
1<=n<=10
1<=V<=1000

Sample Input 1 :
3
1 2 3
4

Sample Output
4

Sample Output Explanation :
Number of ways are - 4 total i.e. (1,1,1,1), (1,1, 2), (1, 3) and (2, 2).
*/

#include<iostream>
using namespace std;
int change(int den[], int num, int value, int** dp){
    
    if(value==0)
        return 1;
    if(num == 0)
        return 0;
    
    if(dp[num][value] != -1)
        return dp[num][value];
        
    int a = 0;
    if(den[0] <= value)
        a = change(den, num, value-den[0], dp);
    int b = change(den+1, num-1, value, dp);
    
    dp[num][value] = a + b;
    return b + a;
}

int countWaysToMakeChange(int den[], int num, int value){
    
    int** dp = new int*[num+1];
    
    for(int i=0; i<=num; i++){
        dp[i] = new int [value+1];
        for(int j=0; j<=value; j++)
            dp[i][j] = -1;
    }
    
    change(den, num, value, dp);
    
    int ans = dp[num][value];
    
    for(int i=0; i<=num; i++)
        delete [] dp[i];
    delete [] dp;
    
    return ans;
}

int main(){

  int numDenominations;
  cin >> numDenominations;
  int* denominations = new int[numDenominations];
  for(int i = 0; i < numDenominations; i++){
    cin >> denominations[i];
  }
  int value;
  cin >> value;

  cout << countWaysToMakeChange(denominations, numDenominations, value);

}


