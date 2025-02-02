#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int longestCommonSubsequence(string s1,string s2,int index1,int index2,int n1,int n2,vector<vector<int>> & dp)
{      
    if(index1>=n1 || index2>=n2) return 0;

    if(dp[index1][index2]!=-1) return dp[index1][index2];

    if(s1[index1]==s2[index2])
    { 
        return 1+longestCommonSubsequence(s1,s2,index1+1,index2+1,n1,n2,dp);
    }
    else
    {
        int firstMove = longestCommonSubsequence(s1,s2,index1+1,index2,n1,n2,dp);
        int secondMove =longestCommonSubsequence(s1,s2,index1,index2+1,n1,n2,dp);
        return dp[index1][index2] = max(firstMove,secondMove);
    }
}

int main()
{
    string s1="ace";
    string s2="abcde";
    int n1=s1.size();
    int n2=s2.size();

    vector<vector<int>> dp(n1+1,vector<int> (n2+1,-1));

    int ans = longestCommonSubsequence(s1,s2,0,0,n1,n2,dp);
    cout<<ans;
    
    
}