class Solution {
public:
    /*
    int findmax(vector<int>& nums,int ind,vector<int>& dp)
    {
        if(ind==0) return nums[0];
        if(ind<0) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int pick=nums[ind]+findmax(nums,ind-2,dp);
        int nonpick=0+findmax(nums,ind-1,dp);
        return dp[ind]=max(pick,nonpick);
    }
    */
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        dp[0]=nums[0];
        int pick=0;
        int notpick=0;
        for(int i=1;i<n;i++)
        {
            pick=nums[i];
            if(i>1)pick=nums[i]+dp[i-2];
            notpick=dp[i-1];
            dp[i]=max(pick,notpick);
        }
        return dp[n-1];
    }
};