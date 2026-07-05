class Solution {
public:
    int findway(int ind,vector<int>&coins,int target,vector<vector<int>>&dp)
    {
        if(ind==0)
        {
            return (target%coins[0]==0);
        }
        if(dp[ind][target]!=-1) return dp[ind][target];
        long long nottaken=findway(ind-1,coins,target,dp);
        long long taken=0;
        if(coins[ind]<=target)
        {
             taken=findway(ind,coins,target-coins[ind],dp);
        }
        return dp[ind][target]=taken+nottaken;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
         return findway(n-1,coins,amount,dp);
       
    }
};