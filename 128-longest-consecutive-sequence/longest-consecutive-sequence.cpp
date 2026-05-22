class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        int max_count=INT_MIN;
        sort(nums.begin(),nums.end());
        int count=1;
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]==nums[i+1]) continue;
            if(nums[i+1]==(nums[i]+1)) count++;
            else 
            {
                max_count=max(max_count,count);
                count=1;
            } 
        }
        max_count=max(max_count,count);
        return max_count;
    }
};