/*
Code : Edit Distance

Given two strings s and t of lengths m and n respectively, find the Edit Distance between the strings. Edit Distance of two strings is minimum number 
of steps required to make one string equal to other. In order to do so you can perform following three operations only :
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
1<= m,n <= 10

Sample Input 1 :
abc
dc

Sample Output 1 :
2
*/

#include <bits/stdc++.h>
using namespace std;

int edit(string s1, string s2, int** A){
    
    if(s1.size()==0 || s2.size()==0)
        return max(s1.size(), s2.size());
    
    if(A[s1.size()][s2.size()] != -1)
        return A[s1.size()][s2.size()];
    
    if(s1[0] == s2[0])
        return edit(s1.substr(1), s2.substr(1), A);
    
    int a=INT_MAX, b=INT_MAX, c=INT_MAX;
    a = edit(s1.substr(1), s2, A);
    b = edit(s1.substr(1), s2.substr(1), A);
    c = edit(s1, s2.substr(1), A);
    
    A[s1.size()][s2.size()] = min(a, min(b, c)) + 1;
    return min(a, min(b, c)) + 1;
}

int editDistance(string s1, string s2){
    
    int** A = new int*[s1.size()+1];
    for(int i=0; i<=s1.size(); i++){
        A[i] = new int[s2.size()+1];
        for(int j=0; j<=s2.size(); j++)
            A[i][j] = -1;
    }
    
    int ans = edit(s1, s2, A);
    
    for(int i=0; i<=s1.size(); i++)
        delete [] A[i];
    delete [] A;
    
    return ans;
}

int main(){

  string s1;
  string s2;

  cin >> s1;
  cin >> s2;

  cout << editDistance(s1,s2) << endl;

}
