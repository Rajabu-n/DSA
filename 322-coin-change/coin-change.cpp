class Solution {
public:
    int findways(vector<int>& coins, int target,int ind,vector<vector<int>>& dp)
    {
            if(ind==0)
            {
                if(target%coins[ind]==0) return target/coins[ind];
                return 1e9;
            }
            if(dp[ind][target]!=-1) return dp[ind][target];
            long long nottake=0+findways(coins,target,ind-1,dp);
            long long take=INT_MAX;
            if(coins[ind]<=target)
            {
                take=1+findways(coins,target-coins[ind],ind,dp);
            }
            return dp[ind][target]= min(take,nottake);
            
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans=findways(coins,amount,n-1,dp);
        if(ans>=1e9) return -1;
        return ans;
    }
};