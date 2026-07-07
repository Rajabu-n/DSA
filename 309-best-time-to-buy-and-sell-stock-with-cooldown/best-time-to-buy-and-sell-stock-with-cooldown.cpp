class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+2,vector<int>(2,0));
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
                   int sell=prices[ind]+dp[ind+2][1];
                     int notsell=dp[ind+1][0];
                     profit=max(sell,notsell);
                }
                dp[ind][buy]=profit;
            }
        }
        return profit;
    }
};