/*
Maximum Square Matrix With All Zeros

Given a n*m matrix which contains only 0s and 1s, find out the size of maximum square sub-matrix with all 0s. You need to return the size of square with all 0s.

Input format :
Line 1 : n and m (space separated positive integers)
Next n lines : m elements of each row (separated by space).

Output Format:
Line 1 : Size of maximum square sub-matrix

Sample Input :
3 3
1 1 0
1 1 1
1 1 1

Sample Output :
1
*/
#include<bits/stdc++.h>
using namespace std;

int findMaxSquareWithAllZeros(int** arr, int row, int col){
    int* dp = new int[row*col];
    int max = 0;
    int flag = 0;
    for(int i=0; i<row; i++)
        if(arr[i][0] == 0){
            dp[i*col] = 1;
            flag = 1;
        }
        else
            dp[col*i] = 0;
    for(int j=0; j<col; j++)
        if(arr[0][j] == 0){
            dp[j] = 1;
            flag = 1;
        }
        else
            dp[j] = 0;
    if(flag == 1)
        max = 1;
    for(int i=1; i<row; i++)
        for(int j=1; j<col; j++){
            if(arr[i][j] != 0){
                dp[i*col+j] = 0;
                continue;
            }
            dp[i*col+j] = 1 + min(dp[(i-1)*col+(j-1)], min(dp[(i-1)*col+j], dp[i*col+(j-1)]));
            max = (max >= dp[i*col+j]) ? max : dp[i*col+j];
        }
    delete [] dp;
    return max;
}
int main()
 {
  int **arr,n,m,i,j;
  cin>>n>>m;
  arr=new int*[n];
  for(i=0;i<n;i++)
      {
       arr[i]=new int[m];
      }
  for(i=0;i<n;i++)
     {
      for(j=0;j<m;j++)
	    {
	     cin>>arr[i][j];
	    }
     }
  cout << findMaxSquareWithAllZeros(arr,n,m) << endl;
  delete arr;
  return 0;
}
