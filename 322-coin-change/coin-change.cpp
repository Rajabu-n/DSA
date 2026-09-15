class Solution {
public:
    int findsum(vector<int>& coins, int sum,int ind,vector<vector<int>>& dp)
    {
        if(ind==0)
        {
            if(sum%coins[0]==0) return sum/coins[0];
            return 1e9;
        }
        if(dp[ind][sum]!=-1) return dp[ind][sum];
        int pick=1e9;
        if(coins[ind]<=sum)pick=1+findsum(coins,sum-coins[ind],ind,dp);
        int notpick=0+findsum(coins,sum,ind-1,dp);
        return dp[ind][sum]=min(pick,notpick);
    }
    int coinChange(vector<int>& coins, int amount) {
         int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans=findsum(coins,amount,n-1,dp);
        if(ans>=1e9) return -1;
        return ans;
    }
};