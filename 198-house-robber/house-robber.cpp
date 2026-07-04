class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        int prev2=0;
        int prev1=nums[0];
        for(int i=1;i<n;i++)
        {
            int pick=nums[i];
            if(i>1) pick+=prev2;
            int notpick=prev1;

            int cur=max(pick,notpick);
            prev2=prev1;
            prev1=cur;
        }
        return prev1;
    }
};