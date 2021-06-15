/*
Largest Piece

Its Gary's birthday today and he has ordered his favourite square cake consisting of '0's and '1's . But Gary wants the biggest piece of '1's and no '0's . 
A piece of cake is defined as a part which consist of only '1's, and all '1's share an edge with eachother on the cake. Given the size of cake N and the 
cake, can you find the size of the biggest piece of '1's for Gary ?
Constraints :
1<=N<=50
Input Format :
Line 1 : An integer N denoting the size of cake 
Next N lines : N characters denoting the cake
Output Format :
Size of the biggest piece of '1's and no '0's
Sample Input :
2
11
01
Sample Output :
3
*/

#include<iostream>
#include<vector>
using namespace std;
#define NMAX 55
#include<iostream>
using namespace std;
int combi[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

int helper(int n, char cake[NMAX][NMAX], int i, int j){
    int count = 1;
    cake[i][j] = 0;
    for(int k=0; k<4; k++)
        if(combi[k][0]+i>-1 && combi[k][0]+i<n && combi[k][1]+j>-1 && combi[k][1]+j<n)
            if(cake[combi[k][0]+i][combi[k][1]+j] == '1')
                count += helper(n, cake, combi[k][0]+i, combi[k][1]+j);
    return count; 
}

int solve(int n, char cake[NMAX][NMAX])
{
	int max = 0;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(cake[i][j] == '1'){
                int size = helper(n, cake, i, j);
                if(size > max)
                    max = size;
            }
    return max;
}
char cake[NMAX][NMAX];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		scanf("%s",cake[i]);
	}
	cout<<solve(n,cake)<<endl;
}
