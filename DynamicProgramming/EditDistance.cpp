#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int editDistance(string word1,string word2,int index1,int index2,int n1,int n2,vector<vector<int>> & dp)
{

    if(index2>=n2 && index1<n1)
    {
        return n1-index1;
    }
    if(index1>=n1 && index2<n2)
    {
        return n2-index2;
    }
    if(index1>=n1 && index2==n2) return 0;

    if(dp[index1][index2]!=-1) return dp[index1][index2];

    if(word1[index1]==word2[index2]) return dp[index1][index2]= editDistance(word1,word2,index1+1,index2+1,n1,n2,dp);

    int insert = 1+editDistance(word1,word2,index1,index2+1,n1,n2,dp);
    int del = 1+ editDistance(word1,word2,index1+1,index2,n1,n2,dp);
    int replace =1 + editDistance(word1,word2,index1+1,index2+1,n1,n2,dp);
    return dp[index1][index2] = min(insert,min(del,replace));
}

int main()
{
    string word1 = "horse";
    string word2 = "ros";
    int n1=word1.size();
    int n2=word2.size();

    vector<vector<int>> dp(n1+1,vector<int> (n2+1,-1));

    int ans = editDistance(word1,word2,0,0,n1,n2,dp);
    cout<<ans;
    
    
}