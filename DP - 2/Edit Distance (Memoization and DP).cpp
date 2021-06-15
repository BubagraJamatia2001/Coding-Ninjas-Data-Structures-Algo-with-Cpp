/*
Code : Edit Distance (Memoization and DP)

Given two strings s and t of lengths m and n respectively, find the Edit Distance between the strings. Edit Distance of two strings is 
minimum number of steps required to make one string equal to other. In order to do so you can perform following three operations only :
1. Delete a character
2. Replace a character with another one
3. Insert a character
Note - Strings don't contain spaces

Input Format :
Line 1 : String s
Line 2 : String t

Output Format :
Line 1 : Edit Distance value

Constraints
1<= m,n <= 20

Sample Input 1 :
abc
dc

Sample Output 1 :
2
*/

#include<iostream>
#include<cstring>
using namespace std;

int editDistance(string s1, string s2){
    
    int m = s1.size();
    int n = s2.size();
    int A[m+1][n+1];
    
    for(int j=0; j<=n; j++)
        A[0][j] = j;
    for(int i=0; i<=m; i++)
        A[i][0] = i;
    
    for(int i=1; i<=m; i++)
        for(int j=1; j<=n; j++)
            if(s1[m-i] == s2[n-j])
                A[i][j] = A[i-1][j-1];
            else
                A[i][j] = 1 + min(A[i-1][j-1], min(A[i][j-1], A[i-1][j]));
    
    return A[m][n];
}
