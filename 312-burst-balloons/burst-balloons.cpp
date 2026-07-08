class Solution {
public:
    int findmax(vector<int>& nums,int i,int j,vector<vector<int>>& dp)
    {
        int maxi=INT_MIN;
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        for(int ind=i;ind<=j;ind++)
        {
            int cost=nums[i-1]*nums[ind]*nums[j+1]+findmax(nums,i,ind-1,dp)+findmax(nums,ind+1,j,dp);
            maxi=max(maxi,cost);
        }
    return dp[i][j]=maxi;
    }
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        //inserting 1 at front and back
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return findmax(nums,1,n,dp);
    }
};