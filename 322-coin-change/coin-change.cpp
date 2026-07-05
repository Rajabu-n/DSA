class Solution {
public:
    /*
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
    */
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,0));
        
        for(int t=0;t<=amount;t++)
        {
            if(t%coins[0]==0)dp[0][t]=t/coins[0];
            else dp[0][t]=1e9;
        }
        for(int ind=1;ind<n;ind++)
        {
            for(int t=0;t<=amount;t++)
            {
                long long nottake=0+dp[ind-1][t];
                long long take=INT_MAX;
                if(coins[ind]<=t)
                {
                    take=1+dp[ind][t-coins[ind]];
                }
                dp[ind][t]=min(take,nottake);
            }

        }
        if(dp[n-1][amount]>=1e9) return -1;
        else return dp[n-1][amount];
    }
};