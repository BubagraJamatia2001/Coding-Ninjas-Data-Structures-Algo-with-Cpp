/*
All possible ways

Given two integers a and b. You need to find and return the count of possible ways in which we can represent the number a as the sum of unique 
integers raise to the power b.
For eg. if a = 10 and b = 2, only way to represent 10 as -
10 = 1^2 + 3^2 
Hence, answer is 1.
Note : x^y represents x raise to the power y
Inout Format :
Two integers a and b (separated by space)
Output Format :
Count
Constraints :
1 <= a <= 10^5
1 <= b <= 50
Sample Input 1 :
10 2
Sample Output 1 :
1
Sample Input 2 :
100 2
Sample Output 2 :
3
*/
#include<bits/stdc++.h>
using namespace std;

int lis(int arr[], int n) {
    int* dp = new int[n];
    dp[0] = 1;
    for(int i=1; i<n; i++){
        int j = i-1, ans = 1;
        for(; j>=0; j--){
            if(arr[i] <= arr[j]) //If current ele is not greater to form increasing subsequence
                continue;
            int len = dp[j] + 1; //Calculating length
            if(len > ans) //If length is greatest among other lengths
                ans = len;
        }
        dp[i] = ans;
    }
    int ans = 0;
    for(int i=0; i<n; i++)
        if(dp[i] > ans)
            ans = dp[i]; //Finding longest subsequence
    delete [] dp;
    return ans;
 }
int main()
{
    int x, n;
    cin >> x >> n;
    cout << allWays(x, n);
    return 0;
}
