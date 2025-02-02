#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int longestIncreasingSubsequence(vector<int> & arr,int prev,int index,int n,vector<vector<int>> & dp)
{   
    if(index>=n) return 0;

    if(dp[prev+1][index]!=-1) return dp[prev+1][index];

    int ntake= 0 + longestIncreasingSubsequence(arr,prev,index+1,n,dp);
    int take=0;
    if(prev ==-1 || arr[index]>arr[prev])
    {
        take= 1+ longestIncreasingSubsequence(arr,index,index+1,n,dp);
    }
    return dp[prev+1][index]= max(take,ntake);
}

int main()
{
    vector<int> arr= {10,9,2,5,3,7,101,18};
    int prev=-1;
    int n=arr.size();
    vector<vector<int>> dp(n+2,vector<int> (n+1,-1));
    int ans= longestIncreasingSubsequence(arr,prev,0,n,dp);
    cout<<ans;
    
    
}