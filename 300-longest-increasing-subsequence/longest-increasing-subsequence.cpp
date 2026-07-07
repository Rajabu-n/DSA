class Solution {
public:
    int findlen(vector<int>& nums,int ind,int prev,vector<vector<int>>& dp)
    {
        if(ind==nums.size()) return 0;
        if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
        int nottake=0+findlen(nums,ind+1,prev,dp);
        int take=0;
        if(prev==-1 || nums[ind]>nums[prev]) take=1+findlen(nums,ind+1,ind,dp);
        return dp[ind][prev+1]=max(take,nottake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return findlen(nums,0,-1,dp);
    }
};