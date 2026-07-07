class Solution {
public:
    //1->buy
    //0->not buy
    int findprofit(vector<int>& prices,int ind,int buy,int n,int profit, vector<vector<int>> &dp)
    {
    
        if(ind==n) return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        if(buy)
        {
            int take=-prices[ind]+findprofit(prices,ind+1,0,n,profit,dp);
            int nottake=findprofit(prices,ind+1,1,n,profit,dp);
            profit= max(take,nottake);
        }
        else 
        {
            int sell=prices[ind]+findprofit(prices,ind+1,1,n,profit,dp);
            int notsell=findprofit(prices,ind+1,0,n,profit,dp);
            profit=max(sell,notsell);
        }
        return dp[ind][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return findprofit(prices,0,1,n,0,dp);
    }
};