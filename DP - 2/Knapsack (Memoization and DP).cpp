/*
Code: Knapsack (Memoization and DP)

A thief robbing a store and can carry a maximal weight of W into his knapsack. There are N items and ith item weigh wi and is of value vi.
What is the maximum value V, that thief can take ?
Space complexity should be O(W).

Input Format :
Line 1 : N i.e. number of items
Line 2 : N Integers i.e. weights of items separated by space
Line 3 : N Integers i.e. values of items separated by space
Line 4 : Integer W i.e. maximum weight thief can carry

Output Format :
Line 1 : Maximum value V

Constraints
1 <= N <= 10^4
1<= wi <= 100
1 <= vi <= 100

Sample Input 1 :
4
1 2 4 5
5 4 8 6
5

Sample Output :
13

*/
#include<bits/stdc++.h>
using namespace std;

int knapsack(int* weights, int* values, int n, int w){
    int A[2][w+1];
    int i=0;
    for(int i=0; i<=1; i++)
        for(int j=0; j<=w; j++)
            A[i][j] = 0;
    while(i<=n){
        int j=0;
        if(i%2)
            for(; j<=w; j++)
                if(weights[i-1] <= j) //i-1 bcoz A is 1 based indexed and weights is not 
                    A[1][j] = max(A[0][j], values[i-1]+A[0][j-weights[i-1]]);
                else
                    A[1][j] = A[0][j];
        else
            for(; j<=w; j++)
                if(weights[i-1] <= j)
                    A[0][j] = max(A[1][j], values[i-1]+A[1][j-weights[i-1]]);
                else
                    A[0][j] = A[1][j]; 
        i++;
    }
    return (n%2 != 0) ? A[1][w] : A[0][w];
}

int main(){

  int n; 
  cin >> n;
  int* weights = new int[n];
  int* values = new int[n];

  for(int i = 0; i < n; i++){
    cin >> weights[i];
  }

  for(int i = 0; i < n; i++){
    cin >> values[i];
  }

  int maxWeight;
  cin >> maxWeight;

  cout << knapsack(weights, values, n, maxWeight);

}


