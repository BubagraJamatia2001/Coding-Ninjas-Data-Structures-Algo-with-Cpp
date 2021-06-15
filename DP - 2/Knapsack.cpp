/*
Code : Knapsack

A thief robbing a store and can carry a maximal weight of W into his knapsack. There are N items and ith item weigh wi and is value vi. 
What is the maximum value V, that thief can take ?

Input Format :
Line 1 : N i.e. number of items
Line 2 : N Integers i.e. weights of items separated by space
Line 3 : N Integers i.e. values of items separated by space
Line 4 : Integer W i.e. maximum weight thief can carry

Output Format :
Line 1 : Maximum value V

Constraints
1 <= N <= 20
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
    int A[n+1][w+1];
    for(int i=0; i<=n; i++)
        for(int j=0; j<=w; j++)
            if(i==0 || j==0)
                A[i][j] = 0;
            else if(weights[i-1] <= j)
                A[i][j] = max(A[i-1][j], values[i-1]+A[i-1][j-weights[i-1]]);
            else
                A[i][j] = A[i-1][j];
    return A[n][w];     
}

int main() {
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

	cout << knapsack(weights, values, n, maxWeight) << endl;
}
