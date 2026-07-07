class Solution {
public:
    //1->buy
    //0->not buy
    /*
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
    */
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        dp[n][0]=dp[n][1]=0;
        int profit=0;
        for(int ind=n-1;ind>=0;ind--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                if(buy)
                {
                    int take=-prices[ind]+dp[ind+1][0];
                    int nottake=dp[ind+1][1];
                    profit= max(take,nottake);
                    
                }
                else 
                {
                    int sell=prices[ind]+dp[ind+1][1];
                     int notsell=dp[ind+1][0];
                     profit=max(sell,notsell);
                }
                dp[ind][buy]=profit;
            }
        }
        return profit;
    }
};